#include "Ref2Effect.h"

using namespace cocos2d;

bool M_Effect::initGLProgramState(const std::string &fragmentFilename)
{
	auto fileUtiles = FileUtils::getInstance();
	auto fragmentFullPath = fileUtiles->fullPathForFilename(fragmentFilename);
	auto fragSource = fileUtiles->getStringFromFile(fragmentFullPath);

	auto glprogram = GLProgram::createWithByteArrays(ccPositionTextureColor_noMVP_vert, fragSource.c_str());

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID || CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	_fragSource = fragSource;
#endif

	_glprogramstate = GLProgramState::getOrCreateWithGLProgram(glprogram);
	_glprogramstate->retain();

	return _glprogramstate != nullptr;
}
M_Effect::M_Effect()
	: _glprogramstate(nullptr)
{
}
M_Effect::~M_Effect()
{
	CC_SAFE_RELEASE_NULL(_glprogramstate);
}
