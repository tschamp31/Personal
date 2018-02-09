`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   23:08:32 04/20/2014
// Design Name:   counter
// Module Name:   C:/Users/Dope/Desktop/Computer Science/SER/tschampa_project3/project3bench.v
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

module project3bench;

	// Inputs
	reg reset;
	reg load;
	reg data;
	reg clk;

	// Instantiate the Unit Under Test (UUT)
	counter uut (
		.reset(reset), 
		.load(load), 
		.data(data), 
		.clk(clk)
	);

	initial begin
	$monitor("counter=%d,clk=%d,load=%d,reset=%d",counter,clk,load,reset);
		// Initialize Inputs
		reset = 0;
		load = 0;
		data = 0;
		clk = 0;

		// Wait 100 ns for global reset to finish
		#100;
		data = 4'b0011;
		reset = 0;
		load = 0;
		clk = 0;
		
		#100;
		data = 0;
		reset = 0;
		load = 0;
		clk = 1;
		
		#100;
		data = 0;
		reset = 1;
		load = 0;
		clk = 0;
		
		#100;
		data = 0;
		reset = 0;
		load = 0;
		clk = 1;
		
		#100;
		data = 0;
		reset = 0;
		load = 0;
		clk = 0;
		
		#100;
		data = 0;
		reset = 0;
		load = 0;
		clk = 1;
		
		#100;
		data = 0;
		reset = 0;
		load = 1;
		clk = 1;
		
		#100;
		data = 0;
		reset = 0;
		load = 0;
		clk = 0;
		
		#100;
		data = 0;
		reset = 0;
		load = 0;
		clk = 1;
		
		#100;
		data = 0;
		reset = 0;
		load = 0;
		clk = 0;
		
		#100;
		data = 0;
		reset = 0;
		load = 0;
		clk = 1;
        
		#100;
		data = 0;
		reset = 0;
		load = 0;
		clk = 1; 
		// Add stimulus here

	end
      
endmodule

