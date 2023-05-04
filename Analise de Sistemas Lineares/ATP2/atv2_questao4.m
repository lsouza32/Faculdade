%% Questão 4

V_pico = 311; %Tensão de pico
V_dc = 0;
periodo = 0.02;
f = 1/periodo;
k = (0:0.00001:periodo);

[linha,coluna] = size(k);
V_sum = 0;

for b=1:1:coluna %Vetor P deve começar na posição 1
    V_sum = V_sum + (V_pico * sin(2*pi*f*k(b))+ V_dc)^2;
end

V_ef = sqrt(V_sum/coluna); % RMS
display(V_ef);

plot(k,(V_pico*sin(2*pi*f*k)+V_dc), 'Color', 'b', 'LineWidth', 2.0);
xlabel('graus [º]');
ylabel('tensão');
title('V x t');
legend ('Senoide');
grid