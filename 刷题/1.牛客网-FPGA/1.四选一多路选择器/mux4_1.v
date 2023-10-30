module mux4_1(
    input wire [1:0] d0,
    input wire [1:0] d1,
    input wire [1:0] d2,
    input wire [1:0] d3,
    input wire [1:0] sel,
    output wire [1:0] mux_out
);

reg [1:0] mux_out_tmp;

always @(*) begin
    case (sel)
        2'b00: mux_out_tmp <= d3;
        2'b01: mux_out_tmp <= d2;
        2'b10: mux_out_tmp <= d1;
        2'd11: mux_out_tmp <= d0;
    endcase
end

assign mux_out = mux_out_tmp;


endmodule 