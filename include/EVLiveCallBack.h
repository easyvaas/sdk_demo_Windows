#pragma once
#include <windows.h>
#include "EVDefs.h"

#ifdef EVLIVE_EXPORTS
#define EVLIVE_API __declspec(dllexport)
#else
#define EVLIVE_API __declspec(dllimport)
#endif

class EVLIVE_API CEVLiveCallBack
{
public:
	CEVLiveCallBack();
	virtual ~CEVLiveCallBack();

	// 初始化SDK--回调;
	virtual void InitSDK_CallBack(IN const bool& bSuccessed, IN const char* strErrInfo) = 0;

	// 初始化Instance--回调;
	virtual void InitInstance_CallBack(IN const bool& bSuccessed, IN const char* strErrInfo) = 0;

	// 设置直播视频参数--回调;
	virtual void SetParameter_CallBack(IN const bool& bSuccessed, IN const char* strErrInfo) = 0;

	// 获取直播视频参数--回调;
	virtual void GetParameter_CallBack(IN const bool& bSuccessed, IN const char* strErrInfo) = 0;

	// 初始化视频窗口--回调;
	virtual void InitVideoWnd_CallBack(IN const bool& bSuccessed, IN const char* strErrInfo) = 0;

	// 准备推流--回调;
	// 失败时,返回错误信息; 成功时,返回推流地址;
	virtual void PrepareStream_CallBack(IN const bool& bSuccessed, IN const char* strErrInfo) = 0;

	// 开始推流--回调;
	virtual void StartStream_CallBack(IN const bool& bSuccessed, IN const char* strErrInfo) = 0;

	// 停止推流--回调;
	virtual void StopStream_CallBack(IN const bool& bSuccessed, IN const char* strErrInfo) = 0;

	//	选中场景源操作--回调;
	virtual void SetSelItemState_CallBack(IN const bool& bSuccessed, IN const char* strErrInfo) = 0;

	// 选中场景源删除--回调;
	virtual void DeleteSelItem_CallBack(IN const bool& bSuccessed, IN const char* strErrInfo) = 0;

	// 游戏源: 获取游戏源列表--回调;
	virtual void GetGameOptions_CallBack(IN const bool& bSuccessed, IN const char* strErrInfo) = 0;

	// 场景添加--回调;
	virtual void AddScene_CallBack(IN const bool& bSuccessed, IN const char* strErrInfo) = 0;

	// 场景编辑--回调;
	virtual void ModifyScene_CallBack(IN const bool& bSuccessed, IN const char* strErrInfo) = 0;

	// 麦克风音量: 设置--回调;
	virtual void SetMicropVolume_CallBack(IN const bool& bSuccessed, IN const char* strErrInfo) = 0;

	// 麦克风音量: 获取--回调;
	virtual void GetMicropVolume_CallBack(IN const bool& bSuccessed, IN const char* strErrInfo) = 0;

	// 扬声器(桌面)音量:设置--回调;
	virtual void SetDesktopVolume_CallBack(IN const bool& bSuccessed, IN const char* strErrInfo) = 0;

	// 扬声器(桌面)音量:获取--回调;
	virtual void GetDesktopVolume_CallBack(IN const bool& bSuccessed, IN const char* strErrInfo) = 0;

	// 获取可用的视频设备列表--回调;
	virtual void GetVideoDevices_CallBack(IN const bool& bSuccessed, IN const char* strErrInfo) = 0;

	// 获取可用的音频设备列表--回调;
	virtual void GetAudioDevices_CallBack(IN const bool& bSuccessed, IN const char* strErrInfo) = 0;

	// 获取选中的场景源类型--回调;
	virtual void GetSelSceneClass_CallBack(IN const bool& bSuccessed, IN const char* strErrInfo) = 0;

	// 获取选中的场景源信息--回调;
	virtual void GetSelSceneInfo_CallBack(IN const bool& bSuccessed, IN const char* strErrInfo) = 0;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// 连麦回调;

	virtual void onJoinChannelSuccess(const char* channel, unsigned int uid, int elapsed) = 0;
	virtual void onRejoinChannelSuccess(const char* channel, unsigned int uid, int elapsed) = 0;
	virtual void onWarning(int warn, const char* msg) = 0;
	virtual void onError(int err, const char* msg) = 0;
	virtual void onAudioQuality(unsigned int uid, int quality, unsigned short delay, unsigned short lost) = 0;
	virtual void onAudioVolumeIndication(const EVAudioVolumeInfo* speakers, unsigned int speakerNumber, int totalVolume) = 0;

	virtual void onLeaveChannel(const EVRtcStats& stat) = 0;
	virtual void onRtcStats(const EVRtcStats& stat) = 0;
	virtual void onMediaEngineEvent(int evt) = 0;

	virtual void onAudioDeviceStateChanged(const char* deviceId, int deviceType, int deviceState) = 0;
	virtual void onVideoDeviceStateChanged(const char* deviceId, int deviceType, int deviceState) = 0;

	virtual void onLastmileQuality(int quality) = 0;
	virtual void onFirstLocalVideoFrame(int width, int height, int elapsed) = 0;
	virtual void onFirstRemoteVideoDecoded(unsigned int uid, int width, int height, int elapsed) = 0;
	virtual void onFirstRemoteVideoFrame(unsigned int uid, int width, int height, int elapsed) = 0;
	virtual void onUserJoined(unsigned int uid, int elapsed) = 0;
	virtual void onUserOffline(unsigned int uid, EV_USER_OFFLINE_REASON_TYPE reason) = 0;
	virtual void onUserMuteAudio(unsigned int uid, bool muted) = 0;
	virtual void onUserMuteVideo(unsigned int uid, bool muted) = 0;
	virtual void onApiCallExecuted(const char* api, int error) = 0;

	virtual void onLocalVideoStats(const EVLocalVideoStats& stats) = 0;
	virtual void onRemoteVideoStats(const EVRemoteVideoStats& stats) = 0;
	virtual void onCameraReady() = 0;
	virtual void onVideoStopped() = 0;
	virtual void onConnectionLost() = 0;
	virtual void onConnectionInterrupted() = 0;

	virtual void onUserEnableVideo(unsigned int uid, bool enabled) = 0;

	virtual void onStartRecordingService(int error) = 0;
	virtual void onStopRecordingService(int error) = 0;
	virtual void onRefreshRecordingServiceStatus(int status) = 0;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// EVMessage

	virtual void onGetMessageServer(const char * serverIp, int serverPort, const char * handShakeKey) = 0;
	virtual void onConnectError(const char * errorInfo) = 0;
	virtual void onConnected() = 0;

	// 加入topic成功，content内容为json字符串，包括私有数据、用户列表信息（用户列表、管理员列表、禁言列表、踢人列表）;
	virtual void onJoinOK(const char * topic, const char ** users, int userNum,
		const char ** privateInfo, int privateInfoNum,
		const char ** managers, int managersNum,
		const char ** shutups, int shutupsNum,
		const char ** kickusers, int kickusersNum) = 0; 
	// 离开topic成功，content内容为json字符串，包括私有数据、用户列表信息（用户列表、管理员列表、禁言列表、踢人列表）;
	virtual void onLeaveOK(const char * content, const char * topic) = 0; 

	// message为json格式字符串；type包括：观看人数、系统消息、礼物、弹幕、直播状态、标题更新等;
	virtual void onNewMessage(const char * message, const char * topic, const char * userData, const char * userId) = 0;
	// 新加入用户列表;
	virtual void onUserJoin(char ** users, int num) = 0;
	// 离开用户的列表;
	virtual void onUserLeave(char ** users, int num) = 0;
	// 点赞数;
	virtual void onLikeCount(int likeCount) = 0;
	// 评论数;
	virtual void onCommentCount(int likeCount) = 0;
	// 饭团数;
	virtual void onRiceRoll(int riceCount) = 0;
	// 正在观看数;
	virtual void onWatchingCount(int watchingCount) = 0;
	// 已观看数;
	virtual void onWatchedCount(int watchedCount) = 0; 
	// 错误列表，见下面列表;
	virtual void onError(int errCode) = 0;			
};