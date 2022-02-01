// Fill out your copyright notice in the Description page of Project Settings.


#include "AC_FloorButton.h"

// Sets default values for this component's properties
UAC_FloorButton::UAC_FloorButton() :
	bIsPressed(false),
	PressOffset(0,0,100)
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
}


// Called when the game starts
void UAC_FloorButton::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UAC_FloorButton::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}