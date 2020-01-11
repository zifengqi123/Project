#ifndef __HM_SDK_VPU__H
#define __HM_SDK_VPU__H
#include "hm_sdk.h"

typedef uint32		hm_vpu_result;
typedef pointer		vpu_user_id;
typedef pointer		vpu_user_data;
typedef pointer		vpu_device_info_handler;
typedef pointer		vpu_video_handler;
typedef pointer		vpu_audio_handler;
typedef pointer		vpu_talk_handler;

typedef pointer		vpu_sign_id;

#define HMCAPI

//	DVSÕ®µ¿ƒ‹¡¶£¨µ•∏ˆ…Ë±∏£®∂‘”¶1∏ˆÕ®µ¿£¨Õ®µ¿∫≈Œ™0£©
typedef struct _VPU_CHANNEL_CAPACITY
{
    char channel_name[260];			// Õ®µ¿√˚≥∆
    char video_name[260];			//	 ”∆µ√˚≥∆
    bool video_support;				//	 ”∆µ÷ß≥÷
    bool audio_support;				//	“Ù∆µ÷ß≥÷
    bool talk_support;				//	∂‘Ω≤÷ß≥÷
    bool ptz_support;				//	‘∆Ã®÷ß≥÷
    uint32 audio_code_type;	//	“Ù∆µ±‡¬Î
    int32 audio_sample;				//	≤…—˘¬
    int32 audio_channel;			//	…˘µ¿
} _VPU_CHANNEL_CAPACITY, *P_VPU_CHANNEL_CAPACITY;

// …Ë±∏–≈œ¢
typedef struct _VPU_DEVICE_INFO
{
    char		dev_name[260];		//	…Ë±∏√˚≥∆
    char		dev_type[64];		//	…Ë±∏¿‡–Õ
    char		dev_sn[14];				//	…Ë±∏SN∫≈
    int32		total_channel;		//	Õ®µ¿◊‹ ˝
    int32		alram_in_count;		//	±®æØ ‰»ÎÕ®µ¿ ˝
    int32		alarm_out_count;	//	±®æØ ‰≥ˆÕ®µ¿ ˝
    int32		sensor_count;		//	¥´∏–∆˜ ˝¡ø
    P_VPU_CHANNEL_CAPACITY  channel_capacity[20];	//	DVSÕ®µ¿ƒ‹¡¶£¨µ•∏ˆ…Ë±∏£®∂‘”¶1∏ˆÕ®µ¿£¨Õ®µ¿∫≈Œ™0£©
} VPU_DEVICE_INFO, *P_VPU_DEVICE_INFO;

HMCAPI hm_vpu_result hm_vpu_init_device_info(P_VPU_DEVICE_INFO);

typedef void(*vpu_net_abnormal)(vpu_user_data, uint32);
typedef struct _VPU_CONNECT_SYSTEM_INFO
{
    char		sign_addr[255];
    uint16		sign_port;
    uint32		sign_interval_time; // µ•Œª∑÷÷”
    char		local_ip[32];
    uint16		local_port;
    
    uint32		type;
    char		soft_ver[128];
    char		hard_ver[128];
    char		dev_type[32];
    char		dev_sn[14];
    
    vpu_net_abnormal net_cb;
    vpu_user_data    data;
} VPU_SYSTEM_INFO, *P_VPU_SYSTEM_INFO;

HMCAPI hm_vpu_result hm_vpu_login_system(P_VPU_SYSTEM_INFO, vpu_user_id* id);
HMCAPI hm_vpu_result hm_vpu_logout_system(vpu_user_id id);

typedef enum {REQUEST_OPEN_VIDEO_EVENT, REQUEST_CLOSE_VIDEO_EVENT};
typedef struct _VPU_FRAME_INFO
{
    uint16	channel;
    uint16	data_type;
    uint16	stream_type;
    uint16	frame_type;
    uint64	absolute_timestamp;
} VPU_FRAME_INFO, *P_VPU_FRAME_INFO;

typedef struct _VPU_FRAME_DATA
{
    VPU_FRAME_INFO frame_info;
    uint32     frame_len;
    cpointer   frame_stream;
} VPU_FRAME_DATA, *P_VPU_FRAME_DATA;

typedef struct _REQUEST_VIDEO
{
    uint32 channel;
    uint32 video_type;
    uint32 stream_type;
} REQUEST_VIDEO, *P_REQUEST_VIDEO;

typedef struct _RESPONSE_VIDEO
{
    uint32 channel;
    uint32 video_code;
    uint32 video_width;
    uint32 video_height;
    uint32 video_fps;
    uint32 gop_size;
} RESPONSE_VIDEO, *P_RESPONSE_VIDEO;

typedef void(*vpu_request_video)(vpu_user_data, uint32 event, pointer info);
HMCAPI hm_vpu_result hm_vpu_register_video_cb(vpu_user_id, vpu_request_video, vpu_user_data);
HMCAPI hm_vpu_result hm_vpu_response_video_request(vpu_user_id, P_RESPONSE_VIDEO);
HMCAPI hm_vpu_result hm_vpu_send_video_data(vpu_user_id, P_VPU_FRAME_DATA);

// “Ù∆µ≤Ÿ◊˜
typedef enum {REQUEST_OPEN_AUDIO_EVENT, REQUEST_CLOSE_AUDIO_EVENT};
typedef struct _REQUEST_AUDIO
{
    uint32 channel;
} REQUEST_AUDIO, *P_REQUEST_AUDIO;

typedef struct _RESPONSE_AUDIO
{
    uint32 channel;
    uint32 audio_type;
    uint32 audio_sample;
    uint32 audio_channel;
} RESPONSE_AUDIO, *P_RESPONSE_AUDIO;

typedef void(*vpu_request_audio)(vpu_user_data, uint32 event, pointer info);
HMCAPI hm_vpu_result hm_vpu_register_audio_event_cb(vpu_user_id, vpu_request_audio, vpu_user_data);
HMCAPI hm_vpu_result hm_vpu_response_audio_request(vpu_user_id, P_RESPONSE_AUDIO);
HMCAPI hm_vpu_result hm_vpu_send_audio_data(vpu_user_id, P_VPU_FRAME_DATA);


typedef struct _VPU_CONNECT_NVS_AUTH_INFO
{
    char user_name[256];
    char user_pwd[256];
    char dev_sn[14];
    char nvs_ip[20];
    uint16 nvs_port;
    vpu_net_abnormal net_cb;
    vpu_user_data    data;
} VPU_CONNECT_NVS_AUTH_INFO, *P_VPU_CONNECT_NVS_AUTH_INFO;

HMCAPI hm_vpu_result hm_vpu_login_nvs(P_VPU_CONNECT_NVS_AUTH_INFO info, vpu_user_id* id);
HMCAPI hm_vpu_result hm_vpu_logout_nvs(vpu_user_id id);
#endif
