#ifndef _MIPI_TX_PARAM_VISIONOX_RM692C9_H_
#define _MIPI_TX_PARAM_VISIONOX_RM692C9_H_

#include <cvi_mipi.h>

#define RM692C9_HACT	1080
#define RM692C9_HSA		4
#define RM692C9_HBP		36
#define RM692C9_HFP		28

#define RM692C9_VACT	1240
#define RM692C9_VSA		4
#define RM692C9_VBP		8
#define RM692C9_VFP		16

#define PIXEL_CLK(x) ((x##_VACT + x##_VSA + x##_VBP + x##_VFP) \
	* (x##_HACT + x##_HSA + x##_HBP + x##_HFP) * 60 / 1000)

struct combo_dev_cfg_s dev_cfg_visionox_rm692c9_1080x1240 = {
	.devno = 0,
	.lane_id = {MIPI_TX_LANE_3, MIPI_TX_LANE_0, MIPI_TX_LANE_CLK, MIPI_TX_LANE_1, MIPI_TX_LANE_2},
	.lane_pn_swap = {true, true, true, true, true},
	.output_mode = OUTPUT_MODE_DSI_VIDEO,
	.video_mode = BURST_MODE,
	.output_format = OUT_FORMAT_RGB_24_BIT,
	.sync_info = {
		.vid_hsa_pixels = RM692C9_HSA,
		.vid_hbp_pixels = RM692C9_HBP,
		.vid_hfp_pixels = RM692C9_HFP,
		.vid_hline_pixels = RM692C9_HACT,
		.vid_vsa_lines = RM692C9_VSA,
		.vid_vbp_lines = RM692C9_VBP,
		.vid_vfp_lines = RM692C9_VFP,
		.vid_active_lines = RM692C9_VACT,
		.vid_vsa_pos_polarity = true,
		.vid_hsa_pos_polarity = true,
	},
	.pixel_clk = PIXEL_CLK(RM692C9),
};

const struct hs_settle_s hs_timing_cfg_visionox_rm692c9_1080x1240 = { .prepare = 6, .zero = 32, .trail = 1 };

static u8 data_visionox_rm692c9_0[] = { 0xFE, 0x00 };
static u8 data_visionox_rm692c9_1[] = { 0xC2, 0x08 };
static u8 data_visionox_rm692c9_2[] = { 0x35, 0x00 };
static u8 data_visionox_rm692c9_3[] = { 0x51, 0X07, 0xFF };
static u8 data_visionox_rm692c9_4[] = { 0x11 };
static u8 data_visionox_rm692c9_5[] = { 0x29 };

const struct dsc_instr dsi_init_cmds_visionox_rm692c9_1080x1240[] = {
	{.delay = 0, .data_type = 0x15, .size = 2, .data = data_visionox_rm692c9_0 },
	{.delay = 0, .data_type = 0x15, .size = 2, .data = data_visionox_rm692c9_1 },
	{.delay = 0, .data_type = 0x15, .size = 2, .data = data_visionox_rm692c9_2 },
	{.delay = 0, .data_type = 0x29, .size = 3, .data = data_visionox_rm692c9_3 },
	{.delay = 120, .data_type = 0x05, .size = 1, .data = data_visionox_rm692c9_4 },
	{.delay = 40, .data_type = 0x05, .size = 1, .data = data_visionox_rm692c9_5 }
};

#else
#error "MIPI_TX_PARAM_VISIONOX_RM692C9 multi-delcaration!!"
#endif // _MIPI_TX_PARAM_VISIONOX_RM692C9_H_