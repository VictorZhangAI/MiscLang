// Generator : SpinalHDL v1.6.4    git head : 598c18959149eb18e5eee5b0aa3eef01ecaa41a1
// Component : CrossingExample
// Git hash  : 883e3261e1539ce4f27f302f74df8bec4bfaa77b
// Date      : 06/02/2025, 06:44:39

`timescale 1ns/1ps 

module CrossingExample (
  input               io_clkA,
  input               io_rstA,
  input               io_clkB,
  input               io_rstB,
  input               io_dataIn,
  output              io_dataOut
);

  reg                 area_clkA_reg;
  (* async_reg = "true" *) reg                 area_clkB_buf0;
  reg                 area_clkB_buf1;

  assign io_dataOut = area_clkB_buf1;
  always @(posedge io_clkA or negedge io_rstA) begin
    if(!io_rstA) begin
      area_clkA_reg <= 1'b0;
    end else begin
      area_clkA_reg <= io_dataIn;
    end
  end

  always @(posedge io_clkB or negedge io_rstB) begin
    if(!io_rstB) begin
      area_clkB_buf0 <= 1'b0;
      area_clkB_buf1 <= 1'b0;
    end else begin
      area_clkB_buf0 <= area_clkA_reg;
      area_clkB_buf1 <= area_clkB_buf0;
    end
  end


endmodule
