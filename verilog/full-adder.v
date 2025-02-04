// Generator : SpinalHDL v1.6.4    git head : 598c18959149eb18e5eee5b0aa3eef01ecaa41a1
// Component : Adder
// Git hash  : 883e3261e1539ce4f27f302f74df8bec4bfaa77b
// Date      : 04/02/2025, 07:04:54

`timescale 1ns/1ps 

module Adder (
);

  wire                cell0_io_a;
  wire                cell0_io_b;
  wire                cell0_io_cin;
  wire                cell1_io_a;
  wire                cell1_io_b;
  wire                cellArray_0_io_a;
  wire                cellArray_0_io_b;
  wire                cellArray_0_io_cin;
  wire                cellArray_1_io_a;
  wire                cellArray_1_io_b;
  wire                cellArray_2_io_a;
  wire                cellArray_2_io_b;
  wire                cellArray_2_io_cin;
  wire                cellArray_3_io_a;
  wire                cellArray_3_io_b;
  wire                cellArray_3_io_cin;
  wire                cellArray_4_io_a;
  wire                cellArray_4_io_b;
  wire                cellArray_4_io_cin;
  wire                cellArray_5_io_a;
  wire                cellArray_5_io_b;
  wire                cellArray_5_io_cin;
  wire                cellArray_6_io_a;
  wire                cellArray_6_io_b;
  wire                cellArray_6_io_cin;
  wire                cellArray_7_io_a;
  wire                cellArray_7_io_b;
  wire                cellArray_7_io_cin;
  wire                cell0_io_sum;
  wire                cell0_io_cout;
  wire                cell1_io_sum;
  wire                cell1_io_cout;
  wire                cellArray_0_io_sum;
  wire                cellArray_0_io_cout;
  wire                cellArray_1_io_sum;
  wire                cellArray_1_io_cout;
  wire                cellArray_2_io_sum;
  wire                cellArray_2_io_cout;
  wire                cellArray_3_io_sum;
  wire                cellArray_3_io_cout;
  wire                cellArray_4_io_sum;
  wire                cellArray_4_io_cout;
  wire                cellArray_5_io_sum;
  wire                cellArray_5_io_cout;
  wire                cellArray_6_io_sum;
  wire                cellArray_6_io_cout;
  wire                cellArray_7_io_sum;
  wire                cellArray_7_io_cout;

  AdderCell cell0 (
    .io_a       (cell0_io_a     ), //i
    .io_b       (cell0_io_b     ), //i
    .io_cin     (cell0_io_cin   ), //i
    .io_sum     (cell0_io_sum   ), //o
    .io_cout    (cell0_io_cout  )  //o
  );
  AdderCell cell1 (
    .io_a       (cell1_io_a     ), //i
    .io_b       (cell1_io_b     ), //i
    .io_cin     (cell0_io_cout  ), //i
    .io_sum     (cell1_io_sum   ), //o
    .io_cout    (cell1_io_cout  )  //o
  );
  AdderCell cellArray_0 (
    .io_a       (cellArray_0_io_a     ), //i
    .io_b       (cellArray_0_io_b     ), //i
    .io_cin     (cellArray_0_io_cin   ), //i
    .io_sum     (cellArray_0_io_sum   ), //o
    .io_cout    (cellArray_0_io_cout  )  //o
  );
  AdderCell cellArray_1 (
    .io_a       (cellArray_1_io_a     ), //i
    .io_b       (cellArray_1_io_b     ), //i
    .io_cin     (cellArray_0_io_cout  ), //i
    .io_sum     (cellArray_1_io_sum   ), //o
    .io_cout    (cellArray_1_io_cout  )  //o
  );
  AdderCell cellArray_2 (
    .io_a       (cellArray_2_io_a     ), //i
    .io_b       (cellArray_2_io_b     ), //i
    .io_cin     (cellArray_2_io_cin   ), //i
    .io_sum     (cellArray_2_io_sum   ), //o
    .io_cout    (cellArray_2_io_cout  )  //o
  );
  AdderCell cellArray_3 (
    .io_a       (cellArray_3_io_a     ), //i
    .io_b       (cellArray_3_io_b     ), //i
    .io_cin     (cellArray_3_io_cin   ), //i
    .io_sum     (cellArray_3_io_sum   ), //o
    .io_cout    (cellArray_3_io_cout  )  //o
  );
  AdderCell cellArray_4 (
    .io_a       (cellArray_4_io_a     ), //i
    .io_b       (cellArray_4_io_b     ), //i
    .io_cin     (cellArray_4_io_cin   ), //i
    .io_sum     (cellArray_4_io_sum   ), //o
    .io_cout    (cellArray_4_io_cout  )  //o
  );
  AdderCell cellArray_5 (
    .io_a       (cellArray_5_io_a     ), //i
    .io_b       (cellArray_5_io_b     ), //i
    .io_cin     (cellArray_5_io_cin   ), //i
    .io_sum     (cellArray_5_io_sum   ), //o
    .io_cout    (cellArray_5_io_cout  )  //o
  );
  AdderCell cellArray_6 (
    .io_a       (cellArray_6_io_a     ), //i
    .io_b       (cellArray_6_io_b     ), //i
    .io_cin     (cellArray_6_io_cin   ), //i
    .io_sum     (cellArray_6_io_sum   ), //o
    .io_cout    (cellArray_6_io_cout  )  //o
  );
  AdderCell cellArray_7 (
    .io_a       (cellArray_7_io_a     ), //i
    .io_b       (cellArray_7_io_b     ), //i
    .io_cin     (cellArray_7_io_cin   ), //i
    .io_sum     (cellArray_7_io_sum   ), //o
    .io_cout    (cellArray_7_io_cout  )  //o
  );

endmodule

//AdderCell replaced by AdderCell

//AdderCell replaced by AdderCell

//AdderCell replaced by AdderCell

//AdderCell replaced by AdderCell

//AdderCell replaced by AdderCell

//AdderCell replaced by AdderCell

//AdderCell replaced by AdderCell

//AdderCell replaced by AdderCell

//AdderCell replaced by AdderCell

module AdderCell (
  input               io_a,
  input               io_b,
  input               io_cin,
  output              io_sum,
  output              io_cout
);


  assign io_sum = ((io_a ^ io_b) ^ io_cin);
  assign io_cout = (((io_a && io_b) || (io_a && io_cin)) || (io_b && io_cin));

endmodule
