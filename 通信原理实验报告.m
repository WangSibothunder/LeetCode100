function exam5_11()
% 主函数：仿真BPSK系统误码率并与理论曲线对比
SNRindB1 = 0:1:12;                    % 仿真用的SNR点（整数步长）
SNRindB2 = 0:0.1:12;                  % 理论曲线用的SNR点（精细步长）
smld_err_prb = zeros(size(SNRindB1)); % 预分配仿真误码率数组
for i = 1:length(SNRindB1)
    smld_err_prb(i) = snr2ps5_11(SNRindB1(i)); % 调用仿真函数计算当前SNR下的误码率
end
theo_err_prb = zeros(size(SNRindB2)); % 预分配理论误码率数组
for i = 1:length(SNRindB2)
    SNR = 10^(SNRindB2(i)/10);        % 将SNR从dB转为线性值
    theo_err_prb(i) = Qfunct(sqrt(SNR)); % 计算理论误码率（BPSK）
end
figure;                               % 创建新图形窗口
semilogy(SNRindB1, smld_err_prb, '*'); % 绘制仿真结果（对数纵轴）
hold on;                              % 保持图形
semilogy(SNRindB2, theo_err_prb);     % 绘制理论曲线
grid on;                              % 显示网格
xlabel('SNR (dB)');                   % x轴标签
ylabel('Error Probability');          % y轴标签
legend('Simulation', 'Theory');       % 图例
title('Comparison of Simulation and Theory BER for BPSK Modulation'); % 标题
end                                   % 主函数结束
function p = snr2ps5_11(snr_in_dB)
E = 1;                                % 信号能量（归一化）
SNR = 10^(snr_in_dB / 10);            % SNR线性值
sgma = E / sqrt(2 * SNR);             % 噪声标准差（双支路AWGN）
N = 10000;                            % 比特数
dsource = rand(1, N) > 0.5;           % 生成随机二进制序列（逻辑值）
numoferr = 0;                         % 初始化错误计数
for i = 1:N
    if ~dsource(i)                    % 发送比特0
        r0 = E + gaussrand(sgma);     % r0支路含信号+噪声
        r1 = gaussrand(sgma);         % r1支路仅噪声
    else                              % 发送比特1
        r0 = gaussrand(sgma);         % r0支路仅噪声
        r1 = E + gaussrand(sgma);     % r1支路含信号+噪声
    end
    decis = (r1 > r0);                % 判决：比较两支路输出
    if decis ~= dsource(i)            % 若判决错误
        numoferr = numoferr + 1;      % 错误计数加1
    end
end
p = numoferr / N;                     % 计算误码率
end
function y = gaussrand(sgma)
y = sgma * randn;                     % 生成高斯白噪声样本
end
function y = Qfunct(x)
y = 0.5 * erfc(x / sqrt(2));          % Q函数实现（基于互补误差函数）
end