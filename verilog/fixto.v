// Generator : SpinalHDL v1.6.4    git head : 598c18959149eb18e5eee5b0aa3eef01ecaa41a1
// Component : Top
// Git hash  : 883e3261e1539ce4f27f302f74df8bec4bfaa77b
// Date      : 04/02/2025, 06:43:16

`timescale 1ns/1ps 

module Top (
  input      [9:0]    A
);

  wire       [4:0]    fixTo_dout;

  SInt10fixTo7_3_ROUNDTOINF fixTo (
    .din     (A[9:0]           ), //i
    .dout    (fixTo_dout[4:0]  )  //o
  );

endmodule

module SInt10fixTo7_3_ROUNDTOINF (
  input      [9:0]    din,
  output     [4:0]    dout
);

  wire       [10:0]   t_t_dout_4;
  wire       [10:0]   t_t_dout_4_1;
  wire       [2:0]    t_when_SInt_l191;
  wire       [7:0]    t_t_dout_6;
  wire       [7:0]    t_t_dout_6_1;
  wire       [10:0]   t_t_dout;
  wire       [10:0]   t_t_dout_1;
  wire       [10:0]   t_t_dout_2;
  wire       [3:0]    t_when_SInt_l131;
  wire       [2:0]    t_when_SInt_l137;
  reg        [7:0]    t_dout;
  wire       [9:0]    t_dout_1;
  wire       [9:0]    t_dout_2;
  wire       [9:0]    t_dout_3;
  wire       [10:0]   t_dout_4;
  wire       [9:0]    t_dout_5;
  wire                when_SInt_l337;
  reg        [7:0]    t_dout_6;
  wire                when_SInt_l191;
  reg        [4:0]    t_dout_7;
  wire                when_SInt_l130;
  wire                when_SInt_l131;
  wire                when_SInt_l137;

  assign t_t_dout_4 = {t_dout_3[9],t_dout_3};
  assign t_t_dout_4_1 = {t_dout_2[9],t_dout_2};
  assign t_when_SInt_l191 = t_dout_4[2 : 0];
  assign t_t_dout_6 = t_dout_4[10 : 3];
  assign t_t_dout_6_1 = 8'h01;
  assign t_t_dout = ($signed(t_t_dout_1) + $signed(t_t_dout_2));
  assign t_t_dout_1 = {t_dout_5[9],t_dout_5};
  assign t_t_dout_2 = {t_dout_1[9],t_dout_1};
  assign t_when_SInt_l131 = t_dout[7 : 4];
  assign t_when_SInt_l137 = t_dout[6 : 4];
  assign t_dout_1 = {{7'h0,1'b1},2'b00};
  assign t_dout_2 = {8'hff,2'b00};
  assign t_dout_3 = din[9 : 0];
  assign t_dout_4 = ($signed(t_t_dout_4) + $signed(t_t_dout_4_1));
  assign t_dout_5 = din[9 : 0];
  assign when_SInt_l337 = t_dout_4[10];
  assign when_SInt_l191 = (|t_when_SInt_l191);
  always @(*) begin
    if(when_SInt_l191) begin
      t_dout_6 = ($signed(t_t_dout_6) + $signed(t_t_dout_6_1));
    end else begin
      t_dout_6 = t_dout_4[10 : 3];
    end
  end

  always @(*) begin
    if(when_SInt_l337) begin
      t_dout = t_dout_6;
    end else begin
      t_dout = (t_t_dout >>> 3);
    end
  end

  assign when_SInt_l130 = t_dout[7];
  assign when_SInt_l131 = (! (&t_when_SInt_l131));
  always @(*) begin
    if(when_SInt_l130) begin
      if(when_SInt_l131) begin
        t_dout_7 = 5'h10;
      end else begin
        t_dout_7 = t_dout[4 : 0];
      end
    end else begin
      if(when_SInt_l137) begin
        t_dout_7 = 5'h0f;
      end else begin
        t_dout_7 = t_dout[4 : 0];
      end
    end
  end

  assign when_SInt_l137 = (|t_when_SInt_l137);
  assign dout = t_dout_7;

endmodule
