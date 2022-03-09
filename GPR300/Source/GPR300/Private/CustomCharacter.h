#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GPR300/Public/UButtonControl.h"
#include "CustomCharacter.generated.h"

UCLASS()
class UControlInput final : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY()
	float MoveX;
	
	UPROPERTY()
	float MoveY;

	UPROPERTY()
	bool bJump;

	UPROPERTY()
	bool bGroundPound;
	
	UControlInput() = default;
	virtual ~UControlInput() override = default;
	
private:
	FInputAxisBinding* Input_MoveX;
	FInputAxisBinding* Input_MoveY;
	UButtonControl Input_Jump;
	UButtonControl Input_GroundPound;

public:
	/*
	FControlInput& operator=(FControlInput& rhs)
	{
		Input_MoveX = rhs.Input_MoveX; rhs.Input_MoveX = nullptr;
		Input_MoveY = rhs.Input_MoveY; rhs.Input_MoveY = nullptr;
		
		Input_Jump = rhs.Input_Jump;
		Input_GroundPound = rhs.Input_GroundPound;
		
		return *this;
	}
	*/
	
	void Bind(UInputComponent* InputComponent)
	{
		Input_MoveX = &InputComponent->BindAxis("MoveX");
		Input_MoveY = &InputComponent->BindAxis("MoveY");
		
		Input_Jump       .Bind(InputComponent, "Jump"       );
		Input_GroundPound.Bind(InputComponent, "GroundPound");
	}
	
	void Update()
	{
		if(Input_MoveX) MoveX = Input_MoveX->AxisValue;
		if(Input_MoveY) MoveY = Input_MoveY->AxisValue;
		
		if(Input_Jump       .bIsBound) bJump = (Input_Jump       .State == EButtonState::Pressed);
		if(Input_GroundPound.bIsBound) bJump = (Input_GroundPound.State == EButtonState::Pressed);
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

	UPROPERTY(VisibleInstanceOnly)
	UControlInput* ControlInput;
};
