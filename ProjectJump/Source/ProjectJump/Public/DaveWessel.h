// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interactables.h"
#include "DaveWessel.generated.h"

/**
 *
 */
UCLASS()
class PROJECTJUMP_API ADaveWessel : public AInteractables
{
	GENERATED_BODY()

public:
	UFUNCTION()
	void OnInteract();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UUserWidget* ShopUI;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<UUserWidget> ShopWidgetClass;

	AController* playerController;
	bool bIsInteracting = false;
	UFUNCTION(BlueprintCallable)
	void callInteract();
	virtual void InteractReceived() override;
	virtual void BeginPlay() override;
};
