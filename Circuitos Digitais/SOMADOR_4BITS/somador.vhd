library IEEE;					
use IEEE.std_logic_1164.all;	
use IEEE.numeric_std.all;

entity somador is
 port (  
  A    :   in  STD_LOGIC_VECTOR(3 DOWNTO 0) ; 
  B    :   in  STD_LOGIC_VECTOR(3 DOWNTO 0) ; 
  cin  :   in  std_logic;  
  R    :   in  std_logic;
  S    :   out STD_LOGIC_VECTOR(3 DOWNTO 0) ;
  cout :   out std_logic;
  bar	 :   out std_logic_vector(6 downto 0)		
 
  
 );
 end entity somador;

architecture main of somador is 
	begin 
	   
	 process(A,B, cin)																	      
		 
				variable	temp : std_logic_vector(3 downto 0);
				variable c    : std_logic;	
				
		begin							

			c := cin;

		   temp(0) := A (0) xor B(0) xor c;
			c := (A(0) and B(0)) or ((A(0) xor B(0)) and c);
			
			temp(1) := A (1) xor B(1) xor c;
			c := (A(1) and B(1)) or ((A(1) xor B(1)) and c);
			
			temp(2) := A (2) xor B(2) xor c;
			c := (A(2) and B(2)) or ((A(2) xor B(2)) and c);
			
			temp(3) := A (3) xor B(3) xor c;
			c := (A(3) and B(3)) or ((A(3) xor B(3)) and c);
			
		   cout <= c;
		   S    <= temp;		
		
			  case temp is															 
				 
				when "0000" => bar <= "1000000";
				when "0001" => bar <= "1111001";
				when "0010" => bar <= "0100100";
				when "0011" => bar <= "0110000";
				when "0100" => bar <= "0011001";										
				when "0101" => bar <= "0010010";										
				when "0110" => bar <= "0000010";										
				when "0111" => bar <= "1111000"; 										
				when "1000" => bar <= "0000000"; 										
				when "1001" => bar <= "0011000";					
				
				when "1010" => bar <= "0001000"; --'A'
				when "1011" => bar <= "1100000"; --'B'
				when "1100" => bar <= "0110001"; --'C'
				when "1101" => bar <= "1000010"; --'D'
				when "1110" => bar <= "0110000"; --'E'
				when "1111" => bar <= "0111000"; --'F'
				
				when others => bar <= "0000000";




			

			  end case;																				  
			
		end process;																		 
	 	
	 
end architecture main;