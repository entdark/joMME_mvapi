#include "cg_local.h"

void	trap_S_StartLocalSound( sfxHandle_t sfx, int channelNum ) {
	//announcer is always hearable, rite?
	if ( channelNum == CHAN_ANNOUNCER || channelNum == CHAN_LOCAL_SOUND )
		trap_S_StartSound( 0, ENTITYNUM_NONE, channelNum, sfx );
	else
		trap_S_StartLocalSound_Real( sfx, channelNum );
}

int	trap_R_Font_StrLenPixels(const char *text, const int iFontIndex, const float scale)
{
	//ent:
	//Raz: HACK! RE_Font_TtrLenPixels only works correctly with 1.0f scale
	float width = (float)trap_R_Font_StrLenPixels_Real( text, iFontIndex, 1.0f);
	return width * scale;
}

void trap_FX_PlayEffectID( int id, vec3_t org, vec3_t fwd )
{
	if (id == cgs.effects.rocketShotEffect				||
		id == cgs.effects.repeaterAltProjectileEffect	||
		id == cgs.effects.flechetteAltShotEffect 		||
		id == cgs.effects.tripmineLaserFX 				||
		id == cgs.effects.itemCone						||
		id == cgs.effects.mSpawn						||
		id == cgs.effects.mSparks						||
		id == cgs.effects.bryarPowerupShotEffect		||
		id == cgs.effects.bryarShotEffect				||
		id == cgs.effects.turretShotEffect				||
		id == cgs.effects.blasterShotEffect				||
		id == cgs.effects.bowcasterShotEffect			||
		id == cgs.effects.repeaterProjectileEffect		||
		id == cgs.effects.repeaterAltProjectileEffect	||
		id == cgs.effects.demp2ProjectileEffect			||
		id == cgs.effects.flechetteShotEffect			||
		id == cgs.effects.saberFizz) {
			if (fx_vfps.integer <= 0)
				fx_vfps.integer = 1;
			if (fxT > cg.time)
				fxT = cg.time;
			if (doFX || cg.time - fxT >= (1000.0f / (float)fx_vfps.integer)) {
				doFX = qtrue;
				fxT = cg.time;
			} else {
				doFX = qfalse;
				return;
			}
	}

//	if (id == cgs.effects.itemCone && !(cg.frametime > 0
//		&& ((cg.frametime < 17 && fmod((float)cg.time, 17.0f) <= cg.frametime)
//		|| cg.frametime >= 17)))
//		return;

	trap_FX_PlayEffectID_Real( id, org, fwd);
}

void trap_FX_PlayEntityEffectID( int id, vec3_t org, 
						vec3_t axis[3], const int boltInfo, const int entNum )
{
	if (id == cgs.effects.forceLightning			||
		id == cgs.effects.forceLightningWide		||
		id == cgs.effects.forceDrainWide			||
		id == cgs.effects.forceDrain				||
		id == cgs.effects.mForceConfustion) {

		if (fx_vfps.integer <= 0)
			fx_vfps.integer = 1;
		if (fxT > cg.time)
			fxT = cg.time;
		if (doFX || cg.time - fxT >= 1000 / fx_vfps.integer) {
			doFX = qtrue;
			fxT = cg.time;
		} else {
			doFX = qfalse;
			return;
		}

		if (id != cgs.effects.mForceConfustion) {
			if (!(cg.frametime > 0
				&& ((cg.frametime < 5 && fmod((double)cg.time, 5.0) <= (double)cg.frametime)
				|| cg.frametime >= 5)))
				return;
		} else if (!(cg.frametime > 0
			&& ((cg.frametime < 17 && fmod((double)cg.time, 17.0) <= (double)cg.frametime)
			|| cg.frametime >= 17)))
			return;
	}
	
	trap_FX_PlayEntityEffectID_Real( id, org, axis, boltInfo, entNum);
}

void trap_FX_AddSprite( addspriteArgStruct_t *p )
{
	if( p->shader == cgs.media.bryarFrontFlash			||
		p->shader == cgs.media.greenFrontFlash			||
		p->shader == cgs.media.lightningFlash			||
		p->shader == cgs.media.yellowDroppedSaberShader	||
		p->shader == cgs.media.redSaberGlowShader		||
		p->shader == cgs.media.greenSaberGlowShader		||
		p->shader == cgs.media.blueSaberGlowShader ) {
			if (fx_vfps.integer <= 0)
				fx_vfps.integer = 1;
			if (fxT > cg.time)
				fxT = cg.time;
			if( doFX || cg.time - fxT >= 1000 / fx_vfps.integer )
			{
				doFX = qtrue;
				fxT = cg.time;
			}
			else 
			{
				doFX = qfalse;
				return;
			}
	}
	trap_FX_AddSprite_Real( p );
}
