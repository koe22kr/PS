// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

DECLARE_LOG_CATEGORY_EXTERN(KHG_LOG, Log, All);

#define KLOG_CALLINFO (FString(__FUNCTION__)+TEXT("(")+FString::FromInt(__LINE__)+TEXT(")"))
#define KLOG_S(Verbosity)  UE_LOG(KHG_LOG, Verbosity,TEXT("%s"),*KLOG_CALLINFO)
#define KLOG(Verbosity,Format, ...) UE_LOG(KHG_LOG,Verbosity,TEXT("%s%s"),*KLOG_CALLINFO,*FString::Printf(Format, ##__VA_ARGS__))