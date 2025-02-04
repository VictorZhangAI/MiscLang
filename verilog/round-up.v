// Generator : SpinalHDL v1.6.4    git head : 598c18959149eb18e5eee5b0aa3eef01ecaa41a1
// Component : Top
// Git hash  : 883e3261e1539ce4f27f302f74df8bec4bfaa77b
// Date      : 04/02/2025, 06:41:22

`timescale 1ns/1ps 

module Top (
  input      [15:0]   a
);

  wire       [15:0]   t_t_f;
  wire       [15:0]   t_t_f_1;
  wire       [15:0]   t_t_f_2;
  wire       [1:0]    t_when_SInt_l131;
  wire       [0:0]    t_when_SInt_l137;
  wire       [14:0]   t_f;
  wire       [14:0]   t_f_1;
  wire       [14:0]   t_f_2;
  reg        [13:0]   f;
  wire                when_SInt_l130;
  wire                when_SInt_l131;
  wire                when_SInt_l137;

  assign t_t_f = ($signed(t_t_f_1) + $signed(t_t_f_2));
  assign t_t_f_1 = {t_f_2[14],t_f_2};
  assign t_t_f_2 = {t_f_1[14],t_f_1};
  assign t_when_SInt_l131 = t_f[14 : 13];
  assign t_when_SInt_l137 = t_f[13 : 13];
  assign t_f_1 = {14'h0,1'b1};
  assign t_f_2 = a[15 : 1];
  assign t_f = (t_t_f >>> 1);
  assign when_SInt_l130 = t_f[14];
  assign when_SInt_l131 = (! (&t_when_SInt_l131));
  always @(*) begin
    if(when_SInt_l130) begin
      if(when_SInt_l131) begin
        f = 14'h2000;
      end else begin
        f = t_f[13 : 0];
      end
    end else begin
      if(when_SInt_l137) begin
        f = 14'h1fff;
      end else begin
        f = t_f[13 : 0];
      end
    end
  end

  assign when_SInt_l137 = (|t_when_SInt_l137);

endmodule
