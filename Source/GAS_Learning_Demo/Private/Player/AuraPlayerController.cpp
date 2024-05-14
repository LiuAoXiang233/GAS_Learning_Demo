// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/AuraPlayerController.h"
#include "EnhancedInputSubsystems.h"


AAuraPlayerController::AAuraPlayerController()
{
	/*
	 *bReplicates是与网络复制相关的变量，它用于指示某个对象或组件是否应该通过网络进行复制。
	 *如果bReplicates设置为true，则引擎会将该对象或组件的状态发送到其他客户端，以确保它们具有相同的状态。
	 *如果设置为false，则不会进行此类复制。
	 *
	 *
	 * 如果一个实体在服务端上发生变化的时候，服务器会同步给其他客户端
	 */
	bReplicates = true;
	
}

void AAuraPlayerController::BeginPlay()
{
	Super::BeginPlay();
	check(AuraContext);

	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	check(Subsystem);
	// 添加输入映射
	Subsystem->AddMappingContext(AuraContext, 0);

	// 唤出鼠标，并且鼠标的样式为默认
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;
	
	FInputModeGameAndUI InputModeData;
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	InputModeData.SetHideCursorDuringCapture(false);
	SetInputMode(InputModeData);
	
	
}
