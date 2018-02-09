`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   19:55:08 04/15/2014
// Design Name:   display
// Module Name:   C:/Users/Dope/Desktop/Computer Science/SER/TsChampa_Project2/testbench.v
// Project Name:  TsChampa_Project2
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: display
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module testbench;

	// Inputs
	reg [3:0] input1;
	reg [3:0] input2;

	// Outputs
	wire [3:0] out;
	wire a;
	wire b;
	wire c;
	wire d;
	wire e;
	wire f;
	wire g;

	// Instantiate the Unit Under Test (UUT)
	inputadderdecoder uut (
		.input1(input1), 
		.input2(input2), 
		.out(out)
	);

	display uut2 (
		.out(out), 
		.a(a), 
		.b(b), 
		.c(c), 
		.d(d), 
		.e(e), 
		.f(f), 
		.g(g)
	);
	
	initial begin
	$monitor("input1=%b,input2=%b,out=%b,a=%b,b=%b,c=%b,d=%b,e=%b,f=%b,g=%b",input1,input2,out,a,b,c,d,e,f,g);
		// Initialize Inputs
		input1 = 0;
		input2 = 0;

		// Wait 100 ns for global reset to finish
		#100;
		input1 = 4'b0001;
		input2 = 4'b0011;
      
		#100;
		input1 = 4'b0101;
		input2 = 4'b0111;
		
		#100;
		input1 = 4'b1001;
		input2 = 4'b1011;

		#100;
		input1 = 4'b1001;
		input2 = 4'b0011;

		#100;
		input1 = 4'b0101;
		input2 = 4'b0011;

		#100;
		input1 = 4'b0000;
		input2 = 4'b0111;		
		// Add stimulus here

	end
      
endmodule

