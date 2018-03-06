// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class NPJ2018SeniorProjectEditorTarget : TargetRules
{
	public NPJ2018SeniorProjectEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		ExtraModuleNames.Add("NPJ2018SeniorProject");
	}
}
