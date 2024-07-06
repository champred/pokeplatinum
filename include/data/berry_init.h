#include "constants/items.h"

/**
 * @brief Table of initial berry states for the various mulch-beds across the
 * overworld.
 *
 * This table is used to initialize the state of the mulch-beds at the time a
 * new game is started. Entries in the table should be read in pairs; the first
 * element is the berry planted in that particular mulch-bed, and the second is
 * the number of that berry that can be harvested from the resulting tree.
 */
static const u16 sBerryInitTable[] = {
    ITEM_ORAN_BERRY,
    1,
    ITEM_CHERI_BERRY,
    1,
    ITEM_CHESTO_BERRY,
    1,
    ITEM_PECHA_BERRY,
    1,
    ITEM_ORAN_BERRY,
    1,
    ITEM_PECHA_BERRY,
    1,
    ITEM_RAZZ_BERRY,
    2,
    ITEM_BLUK_BERRY,
    2,
    ITEM_CHERI_BERRY,
    1,
    ITEM_ORAN_BERRY,
    2,
    ITEM_SITRUS_BERRY,
    1,
    ITEM_WEPEAR_BERRY,
    2,
    ITEM_WEPEAR_BERRY,
    2,
    ITEM_KELPSY_BERRY,
    1,
    ITEM_CHERI_BERRY,
    1,
    ITEM_PECHA_BERRY,
    1,
    ITEM_ORAN_BERRY,
    1,
    ITEM_ORAN_BERRY,
    1,
    ITEM_RAWST_BERRY,
    1,
    ITEM_RAWST_BERRY,
    1,
    ITEM_RAZZ_BERRY,
    1,
    ITEM_RAZZ_BERRY,
    1,
    ITEM_CHERI_BERRY,
    1,
    ITEM_ORAN_BERRY,
    1,
    ITEM_ORAN_BERRY,
    1,
    ITEM_BLUK_BERRY,
    1,
    ITEM_NANAB_BERRY,
    2,
    ITEM_RAZZ_BERRY,
    2,
    ITEM_BLUK_BERRY,
    2,
    ITEM_PINAP_BERRY,
    2,
    ITEM_LEPPA_BERRY,
    1,
    ITEM_CHESTO_BERRY,
    1,
    ITEM_RAZZ_BERRY,
    1,
    ITEM_RAZZ_BERRY,
    1,
    ITEM_PERSIM_BERRY,
    1,
    ITEM_NANAB_BERRY,
    1,
    ITEM_NANAB_BERRY,
    1,
    ITEM_FIGY_BERRY,
    1,
    ITEM_ASPEAR_BERRY,
    1,
    ITEM_ASPEAR_BERRY,
    1,
    ITEM_RAZZ_BERRY,
    1,
    ITEM_PINAP_BERRY,
    1,
    ITEM_SITRUS_BERRY,
    1,
    ITEM_CHESTO_BERRY,
    1,
    ITEM_WIKI_BERRY,
    1,
    ITEM_AGUAV_BERRY,
    1,
    ITEM_PECHA_BERRY,
    1,
    ITEM_ASPEAR_BERRY,
    1,
    ITEM_IAPAPA_BERRY,
    1,
    ITEM_GREPA_BERRY,
    1,
    ITEM_SITRUS_BERRY,
    1,
    ITEM_ASPEAR_BERRY,
    1,
    ITEM_TAMATO_BERRY,
    1,
    ITEM_LUM_BERRY,
    1,
    ITEM_PECHA_BERRY,
    1,
    ITEM_PINAP_BERRY,
    1,
    ITEM_PINAP_BERRY,
    1,
    ITEM_PINAP_BERRY,
    1,
    ITEM_PERSIM_BERRY,
    1,
    ITEM_PERSIM_BERRY,
    1,
    ITEM_NANAB_BERRY,
    1,
    ITEM_NANAB_BERRY,
    1,
    ITEM_AGUAV_BERRY,
    1,
    ITEM_IAPAPA_BERRY,
    1,
    ITEM_RAWST_BERRY,
    1,
    ITEM_RAWST_BERRY,
    1,
    ITEM_CHERI_BERRY,
    1,
    ITEM_SITRUS_BERRY,
    1,
    ITEM_CHESTO_BERRY,
    1,
    ITEM_POMEG_BERRY,
    1,
    ITEM_PECHA_BERRY,
    2,
    ITEM_BLUK_BERRY,
    2,
    ITEM_WIKI_BERRY,
    1,
    ITEM_MAGO_BERRY,
    1,
    ITEM_RAWST_BERRY,
    1,
    ITEM_PERSIM_BERRY,
    1,
    ITEM_FIGY_BERRY,
    1,
    ITEM_PINAP_BERRY,
    2,
    ITEM_LEPPA_BERRY,
    1,
    ITEM_PECHA_BERRY,
    1,
    ITEM_MAGO_BERRY,
    1,
    ITEM_HONDEW_BERRY,
    1,
    ITEM_WIKI_BERRY,
    2,
    ITEM_MAGO_BERRY,
    2,
    ITEM_AGUAV_BERRY,
    2,
    ITEM_QUALOT_BERRY,
    1,
    ITEM_SITRUS_BERRY,
    2,
    ITEM_BLUK_BERRY,
    3,
    ITEM_NANAB_BERRY,
    3,
    ITEM_WEPEAR_BERRY,
    3,
    ITEM_POMEG_BERRY,
    1,
    ITEM_POMEG_BERRY,
    1,
    ITEM_HONDEW_BERRY,
    2,
    ITEM_HONDEW_BERRY,
    2,
    ITEM_KELPSY_BERRY,
    1,
    ITEM_KELPSY_BERRY,
    1,
    ITEM_TAMATO_BERRY,
    1,
    ITEM_TAMATO_BERRY,
    1,
    ITEM_QUALOT_BERRY,
    1,
    ITEM_QUALOT_BERRY,
    1,
    ITEM_POMEG_BERRY,
    1,
    ITEM_POMEG_BERRY,
    1,
    ITEM_HONDEW_BERRY,
    1,
    ITEM_HONDEW_BERRY,
    1,
    ITEM_TAMATO_BERRY,
    1,
    ITEM_TAMATO_BERRY,
    1,
    ITEM_GREPA_BERRY,
    1,
    ITEM_GREPA_BERRY,
    1,
    ITEM_QUALOT_BERRY,
    1,
    ITEM_QUALOT_BERRY,
    1,
    ITEM_LUM_BERRY,
    1,
    ITEM_LEPPA_BERRY,
    1,
    ITEM_QUALOT_BERRY,
    2,
    ITEM_GREPA_BERRY,
    2,
    ITEM_KELPSY_BERRY,
    2,
    ITEM_KELPSY_BERRY,
    2,
    ITEM_GREPA_BERRY,
    1,
    ITEM_GREPA_BERRY,
    1,
};
