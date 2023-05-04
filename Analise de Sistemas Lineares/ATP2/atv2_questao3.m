%% Questão 3

clear
clc

rise_time = 5; %Tempo de subida do sinal
fall_time = 5; % Tempo de caida do sinal
height = 15; % Altura do gráfico
length = 10; % Duração da onda/2
pulse = zeros (2, 4);
pulse(1,2)=height;
pulse(2,2)=rise_time;
pulse(1,3)=height;
pulse(2,3)=pulse(2,2)+length;
pulse(2,4)=pulse(2,3)+fall_time;
plot(pulse(2,:),pulse(1,:))
text(0,0,'-A');
text(5,0,'-B');
text(10,15,'C');
text(15,0,'A');
text(20,0,'B');