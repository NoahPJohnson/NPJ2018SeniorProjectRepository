// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class NPJ2018SeniorProjectTarget : TargetRules
{
	public NPJ2018SeniorProjectTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		ExtraModuleNames.Add("NPJ2018SeniorProject");
	}
}
