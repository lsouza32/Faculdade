%% modulação PWM

fm=25; %% Frequencia da modulacao
fc=400; %% Frequencia onda portadora dente de serra
a = 10; %% Amplitude do sinal da portadora
b = 10; %% Amplitude do sinal de mensagem, deve ser menor que a portadora
t = 0:0.001:1; %% periodo

vc = a.*sawtooth(2*pi*fc*t); %%Multiplicacao da dente de serra
vm = b.*sin(2*pi*fm*t); 
n = length(vc); %% Pega o tamanho do vetor
for i = 1:n %% rodar todo o vetor
    if (vm(i)>=vc(i))
        pwm(i) = 1;
    else
        pwm(i) = 0;
    end
end

% Sinal da mensagem
subplot(3,1,1);
plot(t,vm,'black');
xlabel('Time ----->');
ylabel('Amplitude ----->');
title('Sinal de Mensageml');
legend('Sinal de Mensagem ---->');
grid on;

% Operador
subplot(3,1,2);
plot(t,vc);
xlabel('Amostra ----->');
ylabel('Amplitude ----->');
title('Sinal do operador');
legend('Sinal do operador ---->');
grid on;

% PWM
subplot(3,1,3);
plot(t,pwm,'red');
xlabel('Amostra ----->');
ylabel('Amplitude ----->');
title('Sinal PWM');
legend('Sinal PWM ---->');
axis([0 1 0 2]);
grid on;

