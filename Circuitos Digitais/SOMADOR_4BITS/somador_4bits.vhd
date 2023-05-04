LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;


entity somador_4bits is
	port(
		A, B 	: in	std_logic_vector(3 downto 0);
		C_in	: in std_logic;
		S		: out std_logic_vector(3 downto 0);
		C_out	: out std_logic;
		bar	: out std_logic_vector(6 downto 0) 
	);
end entity;

architecture main of somador_4bits is

	component som_1a
		port(
			X,Y,cin	:	in std_logic;
			saida, cout	:	out std_logic
			);
	end component;	
	
	
	signal v	:	std_logic_vector(3 downto 1);
	signal D :    std_logic_vector(3 downto 0);
	

	begin
		x0:	som_1a	PORT MAP(	a(0),	b(0),	c_in,		D(0), v(1));
		x1:	som_1a	PORT MAP(	a(1),	b(1),	v(1),		D(1), v(2));
		x2:	som_1a	PORT MAP(	a(2),	b(2),	v(2),		D(2), v(3));
		x3:	som_1a	PORT MAP(	a(3),	b(3),	v(3),		D(3), c_out);

		
		process(D)

			begin					
	
			case D is
				when "0000" => bar <= "1000000"; --'0'
				when "0001" => bar <= "1111001"; --'1'
				when "0010" => bar <= "0100100"; --'2'
				when "0011" => bar <= "0110000"; --'3'
				when "0100" => bar <= "0011001"; --'4'
				when "0101" => bar <= "0010010"; --'5'
				when "0110" => bar <= "0000010"; --'6'
				when "0111" => bar <= "1111000"; --'7'
				when "1000" => bar <= "0000000"; --'8'
				when "1001" => bar <= "0010000"; --'9'
				
				when "1010" => bar <= "0001000"; --'A'
				when "1011" => bar <= "0000011"; --'B'
				when "1100" => bar <= "1000110"; --'C'
				when "1101" => bar <= "0100001"; --'D'
				when "1110" => bar <= "0000110"; --'E'
				when "1111" => bar <= "0001110"; --'F'
				
				when others => bar <= "1111111";
			end case;
end process;
		
end architecture;