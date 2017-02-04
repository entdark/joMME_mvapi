# Make sure the user is not executing this script directly
if(NOT InMME)
	message(FATAL_ERROR "Use the top-level cmake script!")
endif(NOT InMME)

add_subdirectory("${SRCDir}/cgame")

if(BuildQVMs)
	# Custom target for building qvm's
	file(MAKE_DIRECTORY "${QVMDir}/tmp")

	foreach(FILE ${MMECGAMEVMSOURCES})
		get_filename_component(FILE ${FILE} NAME_WE)
		
		set(MMECGAMEASMFILES ${MMECGAMEASMFILES} "${FILE}.asm")
	endforeach()

	add_custom_target(qvms
		COMMAND $<TARGET_FILE:${LCC}>
			"-DQ3_VM" "-DJK2_CGAME" "-DMISSIONPACK" "-S" "-Wf-target=bytecode" "-Wf-g" "-I${SRCDir}/cgame" "-I${SRCDir}/game" "-I${SRCDir}/ui" ${MMECGAMEVMSOURCES}

		COMMAND $<TARGET_FILE:${ASM}>
			"-vq3" "-v" "-o" "${QVMDir}/cgame.qvm" ${MMECGAMEASMFILES} ${MMECGAMEASM}

		WORKING_DIRECTORY
			"${QVMDir}/tmp"

		DEPENDS
			${LCC} ${CPP} ${RCC} ${ASM}
	)

	set_property(TARGET qvms PROPERTY PROJECT_LABEL "Build QVMs")
endif()
