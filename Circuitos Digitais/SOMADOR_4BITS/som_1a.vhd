LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;

entity som_1a is
	port(
		X, Y, cin	:	in std_logic;
		saida , cout 	:	out std_logic
		);
end som_1a;

architecture somador of som_1a is
	begin
		saida			<=	X xor Y xor cin;
		cout	<=	(X and Y) or (X and cin) or (Y and cin);
end somador;
		