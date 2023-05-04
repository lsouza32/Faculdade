LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;
USE IEEE.STD_LOGIC_UNSIGNED.ALL;
USE IEEE.NUMERIC_STD.ALL;

entity ULA is
	port(
		a : in std_logic_vector(3 downto 0);
		b : in std_logic_vector(3 downto 0);
		seletor : in std_logic_vector(1 downto 0);
		result : out std_logic_vector(3 downto 0);
		bar	: out std_logic_vector(6 downto 0)
		);
		
end ULA;

architecture main of ULA is 
	signal result_temp : std_logic_vector(3 downto 0);
	signal operator_tmp : boolean;
	
	begin
	
		process(a,b,seletor)
		begin
		
			case(seletor) is -- SELETOR DA OPERACAO (MULTIPLEXADOR)
				--when "00" => result_temp <= a+b; -- SOMA
				--when "01" => result_temp <= a-b; -- SUBTRACAO
				--when "10" => result_temp <= std_logic_vector(to_unsigned(to_integer(unsigned(a)) * to_integer(unsigned(b)),4)); -- MULT
				--when "11" => result_temp <= std_logic_vector(to_unsigned(to_integer(unsigned(a)) / to_integer(unsigned(b)),4)); -- DIV
				when "00" => operator_tmp <= a > b; -- A > B (0=FALSE, 1=TRUE)
				when "01" => operator_tmp <= a < b; -- A < B (0=FALSE, 1=TRUE)
				when "11" => operator_tmp <= a = b; -- A==B (0=FALSE, 1=TRUE)
				when others => result_temp <= a;
			end case;
		end process;
		
		--result <= result_temp; -- Resultado final
		
		process(result_temp)
		begin
		
		-- COMENTAR AS LINHAS 44 A 51 E 74 ('IF' ATE 'ELSE' E 'END IF') CASO DESEJE REALIZAR AS OPERACOES ARITMETICAS 
		if seletor="00" or seletor="01" or seletor="11" then
			case(operator_tmp) is
				when true  => bar <= "1111001"; --'1'
				when false => bar <= "1000000"; --'0'
				when others  => bar <= "1111111";
			end case;
			
		else
			case(result_temp) is	-- DECODIFICADOR							
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
			
		end if;
		
		end process;
		
			
end architecture;	
		
