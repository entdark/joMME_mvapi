# Make sure the user is not executing this script directly
if(NOT InMME)
	message(FATAL_ERROR "Use the top-level cmake script!")
endif(NOT InMME)

set(MMECGAMEHEADERS
	"${SRCDir}/api/mvapi.h"

	"${SRCDir}/cgame/animtable.h"
	"${SRCDir}/cgame/cg_lights.h"
	"${SRCDir}/cgame/cg_local.h"
	"${SRCDir}/cgame/cg_media.h"
	"${SRCDir}/cgame/cg_public.h"
	"${SRCDir}/cgame/fx_local.h"
	"${SRCDir}/cgame/tr_types.h"

	"${SRCDir}/game/anims.h"
	"${SRCDir}/game/bg_local.h"
	"${SRCDir}/game/bg_public.h"
	"${SRCDir}/game/bg_saga.h"
	"${SRCDir}/game/bg_weapons.h"
	"${SRCDir}/game/q_shared.h"
	"${SRCDir}/game/surfaceflags.h"

	"${SRCDir}/ui/ui_shared.h"

	"${SRCDir}/qcommon/qfiles.h"
	"${SRCDir}/qcommon/tags.h"

	"${SRCDir}/ghoul2/g2.h"

	"${SRCDir}/cgame/bg_demos.h"
	"${SRCDir}/cgame/cg_demos.h"
	"${SRCDir}/cgame/cg_demos_math.h"

	"${SRCDir}/qcommon/qmalloc.h"
)

set(MMECGAMESOURCES
	"${SRCDir}/cgame/cg_main.c" # keep this on top (qvm compiler needs VM_Main as the first compiled function)
	"${SRCDir}/cgame/cg_consolecmds.c"
	"${SRCDir}/cgame/cg_draw.c"
	"${SRCDir}/cgame/cg_drawtools.c"
	"${SRCDir}/cgame/cg_effects.c"
	"${SRCDir}/cgame/cg_ents.c"
	"${SRCDir}/cgame/cg_event.c"
	"${SRCDir}/cgame/cg_info.c"
	"${SRCDir}/cgame/cg_light.c"
	"${SRCDir}/cgame/cg_localents.c"
	"${SRCDir}/cgame/cg_marks.c"
	"${SRCDir}/cgame/cg_newDraw.c"
	"${SRCDir}/cgame/cg_players.c"
	"${SRCDir}/cgame/cg_playerstate.c"
	"${SRCDir}/cgame/cg_predict.c"
	"${SRCDir}/cgame/cg_saga.c"
	"${SRCDir}/cgame/cg_scoreboard.c"
	"${SRCDir}/cgame/cg_servercmds.c"
	"${SRCDir}/cgame/cg_snapshot.c"
	"${SRCDir}/cgame/cg_syscalls_wrappers.c"
	"${SRCDir}/cgame/cg_turret.c"
	"${SRCDir}/cgame/cg_view.c"
	"${SRCDir}/cgame/cg_weaponinit.c"
	"${SRCDir}/cgame/cg_weapons.c"
	"${SRCDir}/cgame/fx_blaster.c"
	"${SRCDir}/cgame/fx_bowcaster.c"
	"${SRCDir}/cgame/fx_bryarpistol.c"
	"${SRCDir}/cgame/fx_demp2.c"
	"${SRCDir}/cgame/fx_disruptor.c"
	"${SRCDir}/cgame/fx_flechette.c"
	"${SRCDir}/cgame/fx_force.c"
	"${SRCDir}/cgame/fx_heavyrepeater.c"
	"${SRCDir}/cgame/fx_rocketlauncher.c"

	"${SRCDir}/game/bg_misc.c"
	"${SRCDir}/game/bg_panimate.c"
	"${SRCDir}/game/bg_pmove.c"
	"${SRCDir}/game/bg_saber.c"
	"${SRCDir}/game/bg_slidemove.c"
	"${SRCDir}/game/bg_weapons.c"
	"${SRCDir}/game/q_math.c"
	"${SRCDir}/game/q_shared.c"
	
	"${SRCDir}/ui/ui_shared.c"

	"${SRCDir}/cgame/bg_demos.c"
	"${SRCDir}/cgame/cg_demos.c"
	"${SRCDir}/cgame/cg_demos_camera.c"
	"${SRCDir}/cgame/cg_demos_capture.c"
	"${SRCDir}/cgame/cg_demos_cut.c"
	"${SRCDir}/cgame/cg_demos_dism.c"
	"${SRCDir}/cgame/cg_demos_dof.c"
	"${SRCDir}/cgame/cg_demos_hud.c"
	"${SRCDir}/cgame/cg_demos_line.c"
	"${SRCDir}/cgame/cg_demos_math.c"
	"${SRCDir}/cgame/cg_demos_move.c"
	"${SRCDir}/cgame/cg_demos_weather.c"

	"${SRCDir}/qcommon/qmalloc3.c"
)

set(MMECGAMEASM
	"${SRCDir}/cgame/cg_syscalls.asm"
	PARENT_SCOPE
)

set(MMECGAMEFILES
	${MMECGAMEHEADERS}
	${MMECGAMESOURCES}
	"${SRCDir}/cgame/cg_syscalls.c"
)

set(MMECGAMEVMSOURCES ${MMECGAMESOURCES}
	"${SRCDir}/game/bg_lib.c"
	PARENT_SCOPE
)

add_library(${MMECGAME} SHARED ${MMECGAMEFILES})

# Defines
set(MMECGAMEDefines ${MMECGAMEDefines} "JK2_CGAME")
set(MMECGAMEIncludeDirs ${MMEGLOBALIncludeDirs})

set_target_properties(${MMECGAME} PROPERTIES PREFIX "") # remove "lib" prefix for .so/.dylib files

set_property(TARGET ${MMECGAME} APPEND PROPERTY COMPILE_DEFINITIONS
  $<$<CONFIG:Debug>:${GlobalDefines} ${MMECGAMEDefines} ${DebugDefines}>
  $<$<CONFIG:Release>:${GlobalDefines} ${MMECGAMEDefines} ${ReleaseDefines}>
)

set_target_properties(${MMECGAME} PROPERTIES INCLUDE_DIRECTORIES "${MMECGAMEIncludeDirs}")
set_target_properties(${MMECGAME} PROPERTIES PROJECT_LABEL "cgame")
