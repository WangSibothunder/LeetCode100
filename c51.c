#include <reg52.h>
#include <intrins.h>

// ================== 引脚定义 ==================
sbit RS  = P2^7;   // 寄存器选择 (0:命令, 1:数据)
sbit RW  = P2^6;   // 读写选择 (0:写, 1:读)
sbit EN  = P2^5;   // 使能信号
sbit PSB = P2^3;   // 并/串模式选择 (1:并行)

#define LCD_DATA_PORT P0    // LCD 数据总线

// ================== 常量定义 ==================
#define MAX_KEYS        16          // 按键缓冲区最大容量
#define KEY_INVALID     0xFF        // 无效按键值
#define DELAY_DEBOUNCE  10          // 消抖延时 (ms)
#define DELAY_LOOP      10          // 主循环延时 (ms)
#define DELAY_DISPLAY   200         // 按键响应后防连按延时 (ms)

// ================== 全局变量 ==================
unsigned char key_buffer[MAX_KEYS];  // 存储按键原始值（0~15）
unsigned char key_count = 0;        // 当前已记录按键数量

// ================== 延时函数 ==================
void delay_ms(unsigned int ms) {
    unsigned int i, j;
    for (i = 0; i < ms; i++)
        for (j = 0; j < 114; j++);
}

void delay_us(unsigned char us) {
    while (us--);
}

// ================== LCD 底层操作 ==================
bit lcd_is_busy(void) {
    bit busy_flag;
    LCD_DATA_PORT = 0xFF;   // 设置为输入
    RS = 0;
    RW = 1;
    EN = 1;
    delay_us(5);
    busy_flag = (bit)(LCD_DATA_PORT & 0x80);
    EN = 0;
    return busy_flag;
}

void lcd_wait_ready(void) {
    while (lcd_is_busy());
}

void lcd_write_cmd(unsigned char cmd) {
    lcd_wait_ready();
    RS = 0;
    RW = 0;
    LCD_DATA_PORT = cmd;
    EN = 1;
    delay_us(5);
    EN = 0;
}

void lcd_write_data(unsigned char dat) {
    lcd_wait_ready();
    RS = 1;
    RW = 0;
    LCD_DATA_PORT = dat;
    EN = 1;
    delay_us(5);
    EN = 0;
}

// ================== LCD 高层接口 ==================
void lcd_init(void) {
    PSB = 1;                // 并行模式
    delay_ms(50);           // 上电稳定

    lcd_write_cmd(0x30);    // 基本指令集
    delay_ms(5);
    lcd_write_cmd(0x0C);    // 显示开，光标关
    delay_ms(5);
    lcd_write_cmd(0x01);    // 清屏
    delay_ms(15);
    lcd_write_cmd(0x06);    // 自动右移，不移屏
}

// 设置光标位置：x ∈ [0,3], y ∈ [0,7]
void lcd_set_cursor(unsigned char x, unsigned char y) {
    unsigned char addr;
    switch (x) {
        case 0: addr = 0x80 + y; break;
        case 1: addr = 0x90 + y; break;
        case 2: addr = 0x88 + y; break;
        case 3: addr = 0x98 + y; break;
        default: addr = 0x80;
    }
    lcd_write_cmd(addr);
}

void lcd_print_str(unsigned char x, unsigned char y, const unsigned char *str) {
    lcd_set_cursor(x, y);
    while (*str) {
        lcd_write_data(*str++);
    }
}

void lcd_print_char(unsigned char x, unsigned char y, unsigned char ch) {
    lcd_set_cursor(x, y);
    lcd_write_data(ch);
}

// ================== 键盘扫描 ==================
unsigned char scan_keypad(void) {
    unsigned char row_val, col;

    // 扫描 4 列
    for (col = 0; col < 4; col++) {
        P1 = ~(0x01 << col);          // 拉低当前列（P1.0~P1.3）
        row_val = P1 & 0xF0;          // 读取高4位（行状态）

        if (row_val != 0xF0) {        // 有按键按下
            delay_ms(DELAY_DEBOUNCE);
            row_val = P1 & 0xF0;
            if (row_val != 0xF0) {
                // 等待释放
                while ((P1 & 0xF0) != 0xF0);

                // 计算按键编号：0 ~ 15
                unsigned char row = 0;
                if ((row_val & 0xE0) == 0xE0) row = 0;
                else if ((row_val & 0xD0) == 0xD0) row = 1;
                else if ((row_val & 0xB0) == 0xB0) row = 2;
                else if ((row_val & 0x70) == 0x70) row = 3;
                else return KEY_INVALID;

                return row * 4 + col;
            }
        }
    }
    return KEY_INVALID;
}

// ================== 辅助函数 ==================
unsigned char key_to_ascii(unsigned char key) {
    if (key < 10) return '0' + key;
    else          return 'A' + (key - 10);
}

void display_key_buffer(void) {
    lcd_write_cmd(0x01);  // 清屏
    delay_ms(5);

    lcd_print_str(0, 0, "Keys: ");

    // 显示已记录按键
    for (unsigned char i = 0; i < key_count; i++) {
        unsigned char row = 1 + i / 8;   // 每行最多8字符
        unsigned char col = i % 8;
        lcd_print_char(row, col, key_to_ascii(key_buffer[i]));
    }

    // 显示计数
    lcd_set_cursor(3, 0);
    lcd_print_str(3, 0, "Count: ");
    if (key_count < 10) {
        lcd_write_data('0' + key_count);
    } else {
        lcd_write_data('0' + key_count / 10);
        lcd_write_data('0' + key_count % 10);
    }
}

void clear_key_buffer(void) {
    for (unsigned char i = 0; i < MAX_KEYS; i++) {
        key_buffer[i] = 0;
    }
    key_count = 0;
}

// ================== 主函数 ==================
void main(void) {
    unsigned char key;

    lcd_init();
    clear_key_buffer();

    // 启动提示
    lcd_print_str(0, 0, "Key Scanner");
    lcd_print_str(1, 0, "Press any key");
    lcd_print_str(2, 0, "to start...");
    delay_ms(2000);

    while (1) {
        key = scan_keypad();
        if (key != KEY_INVALID) {
            // 循环覆盖缓冲区
            key_buffer[key_count] = key;
            key_count = (key_count + 1) % MAX_KEYS;

            display_key_buffer();
            delay_ms(DELAY_DISPLAY);  // 防止快速连按
        }
        delay_ms(DELAY_LOOP);
    }
}