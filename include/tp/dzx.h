/**	@file dzx.h
 *	@brief dzr related definitions and structs, mainly used for working with actors
 *
 *	@author AECX
 *  @author Zephiles
 *  @author Lunar Soap
 *	@bug No known bugs.
 */
#pragma once
#include <cstdint>

namespace libtp::tp::dzx
{
    /**
     *  @brief Base class for most/all? Actors
     */
    struct ACTR
    {
        char objectName[8];
        uint32_t parameters;
        float pos[3];
        int16_t rot[2];
        uint16_t flag;
        uint16_t enemyID;
    } __attribute__( ( __packed__ ) );

    /**
     *  @brief Holds information about an ACTR of type TRES
     */
    struct TRES
    {
        char actorName[8];
        uint32_t flags;
        float pos[3];
        int32_t angle;
        uint8_t item;
        uint8_t unk2[3];     // Seems to always be 0xFF
    } __attribute__( ( __packed__ ) );

    /**
     *  @brief Holds information about field a item ACTR (i.e rupees)
     */
    struct ITEM
    {
        char objectName[8];
        uint8_t paramOne;
        uint8_t paramTwo;
        uint8_t membitFlag;
        uint8_t item;
        float pos[3];
        int16_t rot[3];
        uint16_t enemyNum;
    } __attribute__( ( __packed__ ) );

    /**
     *  @brief Holds information about the given dzx Chunktype
     *
     *  Example:
     *  TRES
     *  0001
     *  80401234 = 1 TRES Chunk at this address
     */
    struct ChunkTypeInfo
    {
        char tag[4];
        uint32_t numChunks;
        void* chunkDataPtr;
    };

    /**
     *  @brief Used for spawning actors
     */
    struct ActorPRMClass
    {
        int32_t params;

        float pos[3];

        uint16_t xRot;
        uint16_t yRot;

        uint16_t flag;
        int16_t enemy_id;

        uint8_t flags[9];
        uint8_t room_id;

        uint8_t padding[2];
    } __attribute__( ( __packed__ ) );

    static_assert( sizeof( ACTR ) == 0x20 );
    static_assert( sizeof( TRES ) == 0x20 );
    static_assert( sizeof( ITEM ) == 0x20 );
    static_assert( sizeof( ChunkTypeInfo ) == 0xC );
}     // namespace libtp::tp::dzx