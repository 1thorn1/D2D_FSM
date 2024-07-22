#pragma once

class TimeManager
{
public:
	TimeManager() : previousTime(std::chrono::high_resolution_clock::now()) {}

	void Update() {
		auto currentTime = std::chrono::high_resolution_clock::now();
		std::chrono::duration<float> deltaTimeDuration = currentTime - previousTime;
		deltaTime = deltaTimeDuration.count();
		previousTime = currentTime;
	}

	float GetDeltaTime() const { return deltaTime; }

private:
	std::chrono::high_resolution_clock::time_point previousTime;
	float deltaTime;
};
