%% 1) Modulacao FM
fm=25; %%Frequencia da modulacao
fc=400; %% Frequencia onda portadora
t=0:0.0001:0.01; %%tempo

f1= cos(2*pi*fc*t+(sin(2*pi*fm*t))); %% funcao

figure;
hold all;
plot(t,f1); %% grafico 
title('FM'); %% Titulo
xlabel('Tempo'); %% Nome eixo X
ylabel('Amplitude'); %% Nome eixo Y