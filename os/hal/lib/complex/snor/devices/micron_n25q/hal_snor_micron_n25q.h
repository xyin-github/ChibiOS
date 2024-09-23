/*
    ChibiOS - Copyright (C) 2006..2024 Giovanni Di Sirio

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
*/

/**
 * @file        hal_snor_micron_n25q.h
 * @brief       Generated SNOR Micron N25Q header.
 * @note        This is a generated file, do not edit directly.
 *
 * @addtogroup  HAL_SNOR_MICRON_N25Q
 * @brief       SNOR Micron N25Q driver.
 * @details     Module for SNOR Micron N25Q flash devices.
 * @{
 */

#ifndef HAL_SNOR_MICRON_N25Q_H
#define HAL_SNOR_MICRON_N25Q_H

#include "oop_base_object.h"
#include "hal_snor_base.h"

/*===========================================================================*/
/* Module constants.                                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Module pre-compile time settings.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/

/**
 * @name    Bus width options
 * @{
 */
#define N25Q_BUS_MODE_1LINE                 0U
#define N25Q_BUS_MODE_2LINES                1U
#define N25Q_BUS_MODE_4LINES                2U
/** @} */

/*===========================================================================*/
/* Module macros.                                                            */
/*===========================================================================*/

/*===========================================================================*/
/* Module data structures and types.                                         */
/*===========================================================================*/

/**
 * @brief       Type of a N25Q command configuration structure.
 */
typedef struct n25q_commands n25q_commands_t;

/**
 * @brief       N25Q command configuration structure.
 */
struct n25q_commands {
  /**
   * @brief       Command only.
   */
  uint32_t                  cmd;
  /**
   * @brief       Command and address.
   */
  uint32_t                  cmd_addr;
  /**
   * @brief       Command and data.
   */
  uint32_t                  cmd_data;
  /**
   * @brief       Command, address and data.
   */
  uint32_t                  cmd_addr_data;
};

/**
 * @class       hal_snor_micron_n25q_c
 * @extends     base_object_c, hal_snor_base_c.
 *
 *
 * @name        Class @p hal_snor_micron_n25q_c structures
 * @{
 */

/**
 * @brief       Type of a SNOR Micron N25Q driver class.
 */
typedef struct hal_snor_micron_n25q hal_snor_micron_n25q_c;

/**
 * @brief       Class @p hal_snor_micron_n25q_c virtual methods table.
 */
struct hal_snor_micron_n25q_vmt {
  /* From base_object_c.*/
  void (*dispose)(void *ip);
  /* From hal_snor_base_c.*/
  flash_error_t (*init)(void *ip);
  const flash_descriptor_t * (*get_descriptor)(void *ip);
  flash_error_t (*read)(void *ip, flash_offset_t offset, size_t n, uint8_t *rp);
  flash_error_t (*program)(void *ip, flash_offset_t offset, size_t n, const uint8_t *pp);
  flash_error_t (*start_erase_all)(void *ip);
  flash_error_t (*start_erase_sector)(void *ip, const flash_sector_t *sector);
  flash_error_t (*query_erase)(void *ip, unsigned *msec);
  flash_error_t (*verify_erase)(void *ip, const flash_sector_t *sector);
  flash_error_t (*mmap_on)(void *ip, uint8_t **addrp);
  void (*mmap_off)(void *ip);
  /* From hal_snor_micron_n25q_c.*/
};

/**
 * @brief       Structure representing a SNOR Micron N25Q driver class.
 */
struct hal_snor_micron_n25q {
  /**
   * @brief       Virtual Methods Table.
   */
  const struct hal_snor_micron_n25q_vmt *vmt;
  /**
   * @brief       Implemented interface @p flash_interface_i.
   */
  flash_interface_i         fls;
  /**
   * @brief       Driver state.
   */
  flash_state_t             state;
  /**
   * @brief       Driver configuration.
   */
  const snor_config_t       *config;
  /**
   * @brief       Flash access mutex.
   */
  mutex_t                   mutex;
  /**
   * @brief       Current commands configuration.
   */
  const n25q_commands_t     *commands;
};
/** @} */

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

#ifdef __cplusplus
extern "C" {
#endif
  /* Methods of hal_snor_micron_n25q_c.*/
  void *__n25q_objinit_impl(void *ip, const void *vmt, unsigned bus_width);
  void __n25q_dispose_impl(void *ip);
  flash_error_t __n25q_init_impl(void *ip);
  const flash_descriptor_t *__n25q_get_descriptor_impl(void *ip);
  flash_error_t __n25q_read_impl(void *ip, flash_offset_t offset, size_t n,
                                 uint8_t *rp);
  flash_error_t __n25q_program_impl(void *ip, flash_offset_t offset, size_t n,
                                    const uint8_t *pp);
  flash_error_t __n25q_start_erase_all_impl(void *ip);
  flash_error_t __n25q_start_erase_sector_impl(void *ip,
                                               const flash_sector_t *sector);
  flash_error_t __n25q_query_erase_impl(void *ip, unsigned *msec);
  flash_error_t __n25q_verify_erase_impl(void *ip,
                                         const flash_sector_t *sector);
  flash_error_t __n25q_mmap_on_impl(void *ip, uint8_t **addrp);
  void __n25q_mmap_off_impl(void *ip);
  /* Regular functions.*/
#ifdef __cplusplus
}
#endif

/*===========================================================================*/
/* Module inline functions.                                                  */
/*===========================================================================*/

/**
 * @name        Default constructor of hal_snor_micron_n25q_c
 * @{
 */
/**
 * @memberof    hal_snor_micron_n25q_c
 *
 * @brief       Default initialization function of @p hal_snor_micron_n25q_c.
 *
 * @param[out]    self          Pointer to a @p hal_snor_micron_n25q_c instance
 *                              to be initialized.
 * @param[out]    bus_width     Bus width.
 * @return                      Pointer to the initialized object.
 *
 * @objinit
 */
CC_FORCE_INLINE
static inline hal_snor_micron_n25q_c *n25qObjectInit(hal_snor_micron_n25q_c *self,
                                                     unsigned bus_width) {
  extern const struct hal_snor_micron_n25q_vmt __hal_snor_micron_n25q_vmt;

  return __n25q_objinit_impl(self, &__hal_snor_micron_n25q_vmt, bus_width);
}
/** @} */

#endif /* HAL_SNOR_MICRON_N25Q_H */

/** @} */
