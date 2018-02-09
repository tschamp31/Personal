// Verilog test fixture created from schematic C:\Users\Dope\Desktop\Computer Science\SER\tschampa_Project1\simple_logic.sch - Wed Mar 26 03:51:41 2014

`timescale 1ns / 1ps

module simple_logic_simple_logic_sch_tb();

// Inputs
   reg C;
   reg A;
   reg B;

// Output
   wire F;

// Bidirs

// Instantiate the UUT
   simple_logic UUT (
		.C(C), 
		.A(A), 
		.B(B), 
		.F(F)
   );
// Initialize Inputs
       initial begin
		$monitor("A=%b,B=%b,C=%b,F=%b",A,B,C,F);
		C = 0;
		A = 0;
		B = 0;
		//Wait 100ns for global reset to finish
		#100;
		//Test Setup
		A = 0; B = 0; C =1;
		#100;
		A = 0; B = 1; C =0;
		#100;
		A = 1; B = 0; C =0;
		#100;
		A = 1; B = 1; C =0;
		#100;
		A = 0; B = 1; C =1;
		#100;
		A = 1; B = 0; C =1;
		#100;
		A = 1; B = 1; C =1;
		#100;
		end
endmodule
