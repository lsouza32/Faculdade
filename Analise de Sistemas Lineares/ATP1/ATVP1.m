%% ATIVIDADE PRATICA 1

%%Grafico 1 
%%Amplitude = 10
%% deslocamento vertical = 5 
%%frequência = 2 ciclos por segundo
%%defasagem = 45 graus.

%%Grafico 2 
%%Amplitude = 15 
%%deslocamento vertical = 0 
%%frequência = 3 ciclos por segundo 
%%defasagem = 0 graus.

t= 1:0.01:5; %% Periodo

a1= 10; %%amplitude
b1= 5; %% Deslocamento vertical
fase1= (45*pi)/(180); %%defasagem (convertendo graus para rad)
w1= 2*pi*2; %% Frequencia (2*pi*f)

a2= 15; %%amplitude
b2= 0; %% Deslocamento vertical
fase2= (0*pi)/(180); %%defasagem (convertendo graus para rad)
w2= 2*pi*3; %% Frequencia (2*pi*f)

f1= b1+a1*sin(w1*t+fase1); %%formula 1
f2= b2+a2*sin(w2*t+fase2); %%formula 2

plot(t,f1); %% grafico 1
title('Senoide'); %% Titulo
xlabel('Tempo'); %% Nome eixo X
ylabel('Amplitude');%% Nome eixo Y
hold all; %% Manter plotagem do grafico 1
plot(t,f2); %% grafico 2