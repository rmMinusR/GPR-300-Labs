#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GPR300/Public/UButtonControl.h"
#include "CustomCharacter.generated.h"

USTRUCT()
struct FControlInput
{
	GENERATED_BODY()

	UPROPERTY()
	float MoveX;
	
	UPROPERTY()
	float MoveY;

	UPROPERTY()
	bool bJump;

	UPROPERTY()
	bool bGroundPound;

	FInputAxisBinding* Input_MoveX;
	FInputAxisBinding* Input_MoveY;
	FInputActionBinding* Input_Jump;
	FInputActionBinding* Input_GroundPound;

	FControlInput() = default;
	~FControlInput() = default;

	void Bind()
	{
		
	}
	
	void Update()
	{
		if(Input_MoveX) MoveX = Input_MoveX->AxisValue;
		if(Input_MoveY) MoveY = Input_MoveY->AxisValue;
	}
};

UCLASS()
class ACustomCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACustomCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
private: //Input helper

	//UPROPERTY(VisibleInstanceOnly)
	//FControlInput ControlInput;
};
