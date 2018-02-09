`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    22:44:38 04/20/2014 
// Design Name: 
// Module Name:    project3 
// Project Name: 
// Target Devices: 
// Tool versions: 
// Description: 
//
// Dependencies: 
//
// Revision: 
// Revision 0.01 - File Created
// Additional Comments: 
//
//////////////////////////////////////////////////////////////////////////////////
module counter(reset,load,data,clk,counter);

input reset;
input load;
input [3:0] data;
input clk;

output counter;

reg [3:0] counter;

always@(counter or clk or reset or load or data)
begin

if((data != 0) || (data != 4'b0000))
	begin
		counter = data;
	end
if((counter != 4'b1111) && (clk == 1) && (load == 0) && (reset == 0)) 
	begin
			counter = counter + 4'b0001;
	end
if(reset == 1)
	begin
		counter = 4'b0000;
	end
end
endmodule
