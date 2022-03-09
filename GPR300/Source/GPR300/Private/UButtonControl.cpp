#include "GPR300/Public/UButtonControl.h"

void UButtonControl::Bind(UInputComponent* InputComponent, const FName ControlName)
{
	if(bIsBound) Release();

	this->BoundControlName = ControlName;
	bIsBound = true;
	BindingSource = InputComponent;
	
	BindingPressed  = &InputComponent->BindAction(ControlName, EInputEvent::IE_Pressed , this, &UButtonControl::Input_OnPressed);
	BindingReleased = &InputComponent->BindAction(ControlName, EInputEvent::IE_Released, this, &UButtonControl::Input_OnReleased);
}

void UButtonControl::Release()
{
	if(BindingSource)
	{
		BindingSource->RemoveActionBinding(BoundControlName, EInputEvent::IE_Pressed );
		BindingSource->RemoveActionBinding(BoundControlName, EInputEvent::IE_Released);
	}
	
	bIsBound = false;
	BindingSource = nullptr;
	BindingPressed = nullptr;
	BindingReleased = nullptr;
}