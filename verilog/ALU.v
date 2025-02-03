// Generator : SpinalHDL v1.6.4    git head : 598c18959149eb18e5eee5b0aa3eef01ecaa41a1
// Component : Top
// Git hash  : 883e3261e1539ce4f27f302f74df8bec4bfaa77b
// Date      : 03/02/2025, 07:50:30

`timescale 1ns/1ps 

module Top (
  input               io_src0,
  input               io_src1
);

  wire       [1:0]    bitwiseSelect;
  reg                 bitwiseResult;

  always @(*) begin
    case(bitwiseSelect)
      2'b00 : begin
        bitwiseResult = (io_src0 && io_src1);
      end
      2'b01 : begin
        bitwiseResult = (io_src0 || io_src1);
      end
      2'b10 : begin
        bitwiseResult = (io_src0 ^ io_src1);
      end
      default : begin
        bitwiseResult = io_src0;
      end
    endcase
  end


endmodule
