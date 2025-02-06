// Generator : SpinalHDL v1.6.4    git head : 598c18959149eb18e5eee5b0aa3eef01ecaa41a1
// Component : Top
// Git hash  : 883e3261e1539ce4f27f302f74df8bec4bfaa77b
// Date      : 06/02/2025, 07:11:35

`timescale 1ns/1ps 

module Top (
  input               source_valid,
  output reg          source_ready,
  input      [7:0]    source_payload_red,
  input      [7:0]    source_payload_green,
  input      [7:0]    source_payload_blue,
  output              sink_valid,
  input               sink_ready,
  output     [7:0]    sink_payload_red,
  output     [7:0]    sink_payload_green,
  output     [7:0]    sink_payload_blue,
  input               clk,
  input               resetn
);

  wire                when_Stream_l408;
  reg                 source_thrown_valid;
  reg                 source_thrown_ready;
  wire       [7:0]    source_thrown_payload_red;
  wire       [7:0]    source_thrown_payload_green;
  wire       [7:0]    source_thrown_payload_blue;
  wire                source_thrown_m2sPipe_valid;
  wire                source_thrown_m2sPipe_ready;
  wire       [7:0]    source_thrown_m2sPipe_payload_red;
  wire       [7:0]    source_thrown_m2sPipe_payload_green;
  wire       [7:0]    source_thrown_m2sPipe_payload_blue;
  reg                 source_thrown_rValid;
  reg        [7:0]    source_thrown_rData_red;
  reg        [7:0]    source_thrown_rData_green;
  reg        [7:0]    source_thrown_rData_blue;
  wire                when_Stream_l342;

  assign when_Stream_l408 = (((source_payload_red == 8'h0) && (source_payload_green == 8'h0)) && (source_payload_blue == 8'h0));
  always @(*) begin
    source_thrown_valid = source_valid;
    source_ready = source_thrown_ready;
    if(when_Stream_l408) begin
      source_thrown_valid = 1'b0;
      source_ready = 1'b1;
    end
  end

  assign source_thrown_payload_red = source_payload_red;
  assign source_thrown_payload_green = source_payload_green;
  assign source_thrown_payload_blue = source_payload_blue;
  always @(*) begin
    source_thrown_ready = source_thrown_m2sPipe_ready;
    if(when_Stream_l342) begin
      source_thrown_ready = 1'b1;
    end
  end

  assign when_Stream_l342 = (! source_thrown_m2sPipe_valid);
  assign source_thrown_m2sPipe_valid = source_thrown_rValid;
  assign source_thrown_m2sPipe_payload_red = source_thrown_rData_red;
  assign source_thrown_m2sPipe_payload_green = source_thrown_rData_green;
  assign source_thrown_m2sPipe_payload_blue = source_thrown_rData_blue;
  assign sink_valid = source_thrown_m2sPipe_valid;
  assign source_thrown_m2sPipe_ready = sink_ready;
  assign sink_payload_red = source_thrown_m2sPipe_payload_red;
  assign sink_payload_green = source_thrown_m2sPipe_payload_green;
  assign sink_payload_blue = source_thrown_m2sPipe_payload_blue;
  always @(posedge clk or negedge resetn) begin
    if(!resetn) begin
      source_thrown_rValid <= 1'b0;
    end else begin
      if(source_thrown_ready) begin
        source_thrown_rValid <= source_thrown_valid;
      end
    end
  end

  always @(posedge clk) begin
    if(source_thrown_ready) begin
      source_thrown_rData_red <= source_thrown_payload_red;
      source_thrown_rData_green <= source_thrown_payload_green;
      source_thrown_rData_blue <= source_thrown_payload_blue;
    end
  end


endmodule

