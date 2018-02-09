`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   19:55:21 04/15/2014
// Design Name:   inputadderdecoder
// Module Name:   C:/Users/Dope/Desktop/Computer Science/SER/TsChampa_Project2/testbench2.v
// Project Name:  TsChampa_Project2
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: inputadderdecoder
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module testbench2;

	// Inputs
	reg [3:0] input1;
	reg [3:0] input2;

	// Outputs
	wire [3:0] out;

	// Instantiate the Unit Under Test (UUT)
	inputadderdecoder uut (
		.input1(input1), 
		.input2(input2), 
		.out(out)
	);

	initial begin
		// Initialize Inputs
		input1 = 0;
		input2 = 0;

		// Wait 100 ns for global reset to finish
		#100;
        
		// Add stimulus here

	end
      
endmodule

