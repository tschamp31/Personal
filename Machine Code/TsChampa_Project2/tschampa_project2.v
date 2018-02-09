// Revision: 
// Revision 0.01 - File Created
// Additional Comments: 
//
//	  -a-
//	|f   b|
//   _g_
// |e   c|
//   _d_
//	
// Display Design ^^^
//
//////////////////////////////////////////////////////////////////////////////////
module inputadderdecoder(input1,input2,out);

input[3:0] input1;
input[3:0] input2;

output reg [3:0] out;

always@(input1,input2)
begin
	out = input1 + input2;
end
endmodule

module display(out,a, b, c, d, e, f, g);

input[3:0] out;
output reg a, b, c, d, e, f, g;

always@(a,b,c,d,e,g,f,out)
begin
case(out)
	4'b0000: begin a=1; b=1; c=1; d=1; e=1; f=1; g=0; end //0
	
	4'b0001: begin a=0; b=1; c=1; d=0; e=0; f=0; g=0; end //1
	
	4'b0010: begin a=1; b=1; c=0; d=1; e=1; f=0; g=1; end //2
	
	4'b0011: begin a=1; b=1; c=1; d=1; e=0; f=0; g=1; end //3
	
	4'b0100: begin a=0; b=1; c=1; d=0; e=0; f=1; g=1; end //4
	
	4'b0101: begin a=1; b=0; c=1; d=1; e=0; f=1; g=1; end //5
	
	4'b0110: begin a=1; b=0; c=1; d=1; e=1; f=1; g=1; end //6
	
	4'b0111: begin a=1; b=1; c=1; d=0; e=0; f=0; g=0; end //7
	
	4'b1000: begin a=1; b=1; c=1; d=1; e=1; f=1; g=1; end //8
	
	4'b1001: begin a=1; b=1; c=1; d=1; e=0; f=1; g=1; end //9
	
	4'b1001: begin a=1; b=1; c=1; d=0; e=1; f=1; g=1; end //A
	
	4'b1001: begin a=0; b=0; c=1; d=1; e=1; f=1; g=1; end //b
	
	4'b1001: begin a=1; b=0; c=0; d=1; e=1; f=1; g=0; end //C
	
	4'b1001: begin a=0; b=1; c=1; d=1; e=1; f=0; g=1; end //d
	
	4'b1001: begin a=1; b=0; c=0; d=1; e=1; f=1; g=1; end //E
	
	4'b1001: begin a=1; b=0; c=0; d=0; e=1; f=1; g=1; end //F
	
	default: begin a=0; b=0; c=1; d=1; e=1; f=1; g=0; end //Overflow
	
endcase
end
endmodule