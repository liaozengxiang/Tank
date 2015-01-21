-- 简单 AI 的实现
-- Copyright (C) 2015. All rights reserved


-- 新的关卡开始，由 C++ 程序调用
-- 参数:
--       nStageID  关卡编号
function OnNewStage(nStageID)
	print("Stage " .. tostring(nStageID) .. " started");
end

OnNewStage(1);
