#pragma once

#include "CoreMinimal.h"
#include "Components/InputComponent.h"
#include "UButtonControl.generated.h"

UENUM(BlueprintType)
enum EButtonState
{
	Pressed,
	Released 
};

UCLASS(BlueprintType)
class GPR300_API UButtonControl final : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, Transient, BlueprintReadOnly)
	bool bIsBound;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FName BoundControlName;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TEnumAsByte<EButtonState> State;
	
	void Bind(UInputComponent* InputComponent, FName ControlName);
	void Release();
	
private:
	FInputActionBinding* BindingPressed;
	FInputActionBinding* BindingReleased;
	UPROPERTY(Transient) UInputComponent* BindingSource;
	
	void Input_OnPressed() { State = EButtonState::Pressed; }
	void Input_OnReleased() { State = EButtonState::Released; }
	
public:
	
	UButtonControl& operator=(UButtonControl& rhs)
	{
		if(&rhs == this) return *this;
		
		Release();
		
		bIsBound = false;
		BoundControlName = rhs.BoundControlName;
		BindingSource = rhs.BindingSource;
		State = rhs.State;

		rhs.Release();
		Bind(BindingSource, BoundControlName);
		
		return *this;
	}
	
	UButtonControl() :
		bIsBound(false),
		BoundControlName(""),
		BindingPressed(nullptr),
		BindingReleased(nullptr),
		BindingSource(nullptr)
	{
		
	}
	
	virtual ~UButtonControl() override
	{
		Release();
	}
};