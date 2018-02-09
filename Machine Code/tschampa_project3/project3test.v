`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   23:30:47 04/20/2014
// Design Name:   counter
// Module Name:   C:/Users/Dope/Desktop/Computer Science/SER/tschampa_project3/project3test.v
// Project Name:  tschampa_project3
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: counter
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module project3test;

	// Inputs
	reg reset;
	reg load;
	reg [3:0] data;
	reg clk;

	// Outputs
	wire [3:0] counter;

	// Instantiate the Unit Under Test (UUT)
	counter uut (
		.reset(reset), 
		.load(load), 
		.data(data), 
		.clk(clk), 
		.counter(counter)
	);

	initial begin
	$monitor("counter=%b,reset=%b,load=%b,data=%b,clk=%b",counter,reset,load,data,clk);  
		// Initialize Inputs
		reset = 0;
		load = 0;
		data = 0;
		clk = 0;

		// Wait 100 ns for global reset to finish
		#100;
      reset = 0;
		load = 0;
		data = 4'b1011;
		clk = 0;

		#100;
      reset = 1;
		load = 0;
		data = 0;
		clk = 0;  

		#100;
      reset = 0;
		load = 0;
		data = 0;
		clk = 1;  

		#100;
      reset = 0;
		load = 0;
		data = 0;
		clk = 1;  

		#100;
      reset = 0;
		load = 1;
		data = 0;
		clk = 1;  

		#100;
      reset = 1;
		load = 0;
		data = 0;
		clk = 0;  

		#100;
      reset = 0;
		load = 0;
		data = 4'b0111;
		clk = 1;  

		#100;
      reset = 0;
		load = 1;
		data = 0;
		clk = 1;  

		#100;
      reset = 0;
		load = 0;
		data = 0;
		clk = 1;  

		#100;
      reset = 0;
		load = 0;
		data = 0;
		clk = 1;  

		#100;
      reset = 1;
		load = 0;
		data = 0;
		clk = 0;  		
		// Add stimulus here

	end
      
endmodule

