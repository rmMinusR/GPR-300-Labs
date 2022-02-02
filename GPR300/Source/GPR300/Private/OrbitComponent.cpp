// Fill out your copyright notice in the Description page of Project Settings.


#include "OrbitComponent.h"

// Sets default values for this component's properties
UOrbitComponent::UOrbitComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UOrbitComponent::BeginPlay()
{
	Super::BeginPlay();

	//TODO should these be in a different method?
	orbitCenterPos = GetOwner()->GetActorLocation();
	orbitAngularPos = 0;
}


// Called every frame
void UOrbitComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	orbitAngularPos += orbitAngularSpeed * DeltaTime;
    FVector diff = FVector(cos(orbitAngularPos)*orbitRadius, sin(orbitAngularPos)*orbitRadius, 0);
    
    GetOwner()->SetActorLocation(orbitCenterPos+diff);
}

