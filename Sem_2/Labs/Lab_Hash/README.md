# 1) Задание
## Реализовать Хэш-таблциу
1. Создать динамический массив из записей (в соответствии с вариантом), содержащий не менее 100 элементов. Для заполнения элементов массива использовать ДСЧ.
2. Предусмотреть сохранение массива в файл и загрузку массива из файла.
3. Предусмотреть возможность добавления и удаления элементов из массива (файла).
4. Выполнить поиск элемента в массиве по ключу в соответствии с вариантом. Для поиска использовать хэш-таблицу.
5. Подсчитать количество коллизий при размере хэш-таблицы 40, 75 и 90 элементов.
20 вариант задания : 
Данные: ФИО, дата_рождения, №паспорта,
Ключ (string): дата_рождения,
Хэш-функция: H(k)= [M (kAmod1)], 0<A<1, mod1 – получение дробной части, [] – получение целой части
Метод рехеширования: Метод цепочек

# 2) Код программы
```cpp
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <cstdlib>
using namespace std;
struct Record 
{
    string name;
    string birth_date;
    string passport_number;
    Record* next;
};
class HashTable 
{
private:
    static const int TABLE_SIZE = 100;
    Record* table[TABLE_SIZE];

    int hashFunction(string key) 
    {
        double A = 0.6180339887;
        int hash = floor(TABLE_SIZE * fmod(stod(key) * A, 1));
        return hash;
    }
public:
    HashTable() 
    {
        for (int i = 0; i < TABLE_SIZE; i++) 
        {
            table[i] = nullptr;
        }
    }
    void insertRecord(Record* record) 
    {
        int hash = hashFunction(record->birth_date);
        record->next = table[hash];
        table[hash] = record;
    }
    void deleteRecord(string key) 
    {
        int hash = hashFunction(key);
        Record* current = table[hash];
        Record* prev = nullptr;
        while (current != nullptr) 
        {
            if (current->birth_date == key) 
            {
                if (prev == nullptr) 
                {
                    table[hash] = current->next;
                } 
                else 
                {
                    prev->next = current->next;
                }
                delete current;
                break;
            }
            prev = current;
            current = current->next;
        }
    }
    void saveToFile(string filename) 
    {
        ofstream file(filename);
        for (int i = 0; i < TABLE_SIZE; i++) 
        {
            Record* current = table[i];
            while (current != nullptr)
            {
                file << "name = " << current->name << endl << "year = " << current->birth_date << endl << "pass = " << current->passport_number << "\n---------------------------------------\n";
                current = current->next;
            }
        }
        file.close();
    }
    void loadFromFile(string filename) 
    {
        ifstream file(filename);
        if (file.is_open()) 
        {
            Record record;
            while (file >> record.name >> record.birth_date >> record.passport_number) 
            {
                Record* newRecord = new Record;
                newRecord->name = record.name;
                newRecord->birth_date = record.birth_date;
                newRecord->passport_number = record.passport_number;
                insertRecord(newRecord);
            }
            file.close();
        }
    }
    void displayCollisions() 
    {
        int table_sizes[] = {40, 75, 90};
        for (int size : table_sizes) 
        {
            int collisions = 0;
            for (int i = 0; i < size; i++) 
            {
                Record* current = table[i];
                if (current != nullptr) 
                {
                    int count = 0;
                    while (current != nullptr) 
                    {
                        count++;
                        current = current->next;
                    }
                    if (count > 1) 
                    {
                        collisions += count - 1;
                    }
                }
            }
            cout << "Number of collisions for table size " << size << ": " << collisions / 2 << endl;
        }
    }
};
string GenerateName()
{
    const int N = 9;
    string s;
    for (int j = 0; j < N - 1; j++)
        s += 'a' + rand()%26;
    return s;
}
int main() 
{
    srand(time(0));
    HashTable ht;
    for (int i = 0; i < 100; i++) 
    {
        Record* record = new Record;
        record->name = GenerateName() + '_' + GenerateName() + '_' + GenerateName();
        record->birth_date = to_string(1950 + rand() % 70);
        record->passport_number = "PASS №" + to_string(rand() % 1000000);
        record->next = nullptr;
        ht.insertRecord(record);
    }
    ht.saveToFile("records.txt");
    HashTable ht2;
    ht2.loadFromFile("records.txt");
    ht2.displayCollisions();
    return 0;
}
```
# 3) Блок-схема
<image src ="https://github.com/MishaNyasha/Labs_PSTU_2023/blob/main/Sem_2/Labs/Lab_Hash/diagrams/Main.png">
    <image src ="https://github.com/MishaNyasha/Labs_PSTU_2023/blob/main/Sem_2/Labs/Lab_Hash/diagrams/HashTable.png">
    <image src ="https://github.com/MishaNyasha/Labs_PSTU_2023/blob/main/Sem_2/Labs/Lab_Hash/diagrams/GenerateName.png">
    <image src ="https://github.com/MishaNyasha/Labs_PSTU_2023/blob/main/Sem_2/Labs/Lab_Hash/diagrams/class_HashTable%20.png">
    <image src ="https://github.com/MishaNyasha/Labs_PSTU_2023/blob/main/Sem_2/Labs/Lab_Hash/diagrams/deleteRecord.png">
    <image src ="https://github.com/MishaNyasha/Labs_PSTU_2023/blob/main/Sem_2/Labs/Lab_Hash/diagrams/displayCollisions.png">
    <image src ="https://github.com/MishaNyasha/Labs_PSTU_2023/blob/main/Sem_2/Labs/Lab_Hash/diagrams/hashFunction.png">
    <image src ="https://github.com/MishaNyasha/Labs_PSTU_2023/blob/main/Sem_2/Labs/Lab_Hash/diagrams/insertRecord.png">
    <image src ="https://github.com/MishaNyasha/Labs_PSTU_2023/blob/main/Sem_2/Labs/Lab_Hash/diagrams/loadFromFile.png">
    <image src ="https://github.com/MishaNyasha/Labs_PSTU_2023/blob/main/Sem_2/Labs/Lab_Hash/diagrams/saveToFile.png">
    <image src ="https://github.com/MishaNyasha/Labs_PSTU_2023/blob/main/Sem_2/Labs/Lab_Hash/diagrams/struct_Record.png">
  
# 4) Результат
```cpp
name = jrcbvlqg_sfhybhpq_gzgwhbwa
year = 2008
pass = PASS №665102
---------------------------------------
name = bhncetth_ttktvotr_cgykkjee
year = 2008
pass = PASS №385105
---------------------------------------
name = jxecohlb_ayueenzq_uklflnnl
year = 1987
pass = PASS №269351
---------------------------------------
name = xwbaavzl_yvnasuag_cnfnduhf
year = 1987
pass = PASS №740671
---------------------------------------
name = ztgwvgef_jlskpthp_nafzddif
year = 1966
pass = PASS №526225
---------------------------------------
name = cpqsjpak_oxwdjsjw_uagzlkvu
year = 2000
pass = PASS №794659
---------------------------------------
name = nlqhiotf_jfreneau_jnykgjfq
year = 2013
pass = PASS №508212
---------------------------------------
name = yjvnvcnf_lugjkuuv_jvkzabvg
year = 2013
pass = PASS №20896
---------------------------------------
name = kqxfhjpn_okmyttta_iiybiadk
year = 1958
pass = PASS №886048
---------------------------------------
name = gpjrhokr_arpaakrd_saqrjfeu
year = 1992
pass = PASS №978009
---------------------------------------
name = jmbrakie_sbozgauu_vbitnidc
year = 1971
pass = PASS №445150
---------------------------------------
name = dwvndfwq_joaqeoja_vqyqkavo
year = 1971
pass = PASS №446108
---------------------------------------
name = ailntxlp_cvicvoow_xovbwgie
year = 1950
pass = PASS №862822
---------------------------------------
name = xtrmjwyt_rkvwpnab_tmrscbwk
year = 1950
pass = PASS №598371
---------------------------------------
name = vhzsupxt_mltfhxgu_qmqplund
year = 1950
pass = PASS №525410
---------------------------------------
name = fyjntews_ojldpxpk_pugkyywo
year = 1984
pass = PASS №807458
---------------------------------------
name = yhcxocmb_fbtvekav_iohjildh
year = 1984
pass = PASS №942594
---------------------------------------
name = qdzzfvdd_eylvzexk_eyqqwptw
year = 1963
pass = PASS №241904
---------------------------------------
name = rizlmeaf_eefyxuow_ytpghaht
year = 1976
pass = PASS №297790
---------------------------------------
name = tkqsvdkk_xvtqlbli_gqvsflsy
year = 1976
pass = PASS №582223
---------------------------------------
name = xjtitosj_gyiawfxs_dvibxotu
year = 2010
pass = PASS №571742
---------------------------------------
name = oviyzlkz_yvfaisle_wwykokhr
year = 1955
pass = PASS №2528
---------------------------------------
name = ahuokfgc_zaztontq_wdppqpyn
year = 1955
pass = PASS №414601
---------------------------------------
name = ifrzzvvh_frkkqlmb_iuxhzcxu
year = 1989
pass = PASS №413358
---------------------------------------
name = nmwttvme_muvcsoyc_waacrkto
year = 1989
pass = PASS №678244
---------------------------------------
name = pxrkkqzk_zfhzuqwm_pdnchxcc
year = 1989
pass = PASS №194472
---------------------------------------
name = avbamkxs_aeuprupl_weygtste
year = 1968
pass = PASS №142013
---------------------------------------
name = eseewrtt_idnduzyp_cfkkagmd
year = 1968
pass = PASS №113784
---------------------------------------
name = rewcgtgc_rhxrsgqc_kvceonxd
year = 1968
pass = PASS №91906
---------------------------------------
name = bkqhlkhi_nfqqetxx_fxdwsapc
year = 2002
pass = PASS №53129
---------------------------------------
name = eavjgbxa_aapecluf_ojjbfoyl
year = 2015
pass = PASS №282873
---------------------------------------
name = klcwyeuv_bmgjqehb_lrqvxrjp
year = 1960
pass = PASS №250732
---------------------------------------
name = emspovoj_uodreofe_dvgmcbea
year = 1960
pass = PASS №89487
---------------------------------------
name = uzpvasvj_eiofzsbl_qbtilduk
year = 1994
pass = PASS №431086
---------------------------------------
name = eucyefki_equugpeq_kdtyqtzh
year = 1994
pass = PASS №659071
---------------------------------------
name = nesxtvcc_euamcnqz_wcfgxjwo
year = 1973
pass = PASS №200399
---------------------------------------
name = ygxxfzvw_lzrymkwb_ufpblzgg
year = 2007
pass = PASS №657242
---------------------------------------
name = ctgstvyn_ycjxsprs_ensbuqdz
year = 1952
pass = PASS №195855
---------------------------------------
name = bfjbaaon_ldvxosim_coqvwkif
year = 1952
pass = PASS №828038
---------------------------------------
name = yddmbwua_shubdygi_zfmfdmau
year = 1952
pass = PASS №575606
---------------------------------------
name = thfzqdev_urxvlsef_ginfwnml
year = 1965
pass = PASS №999599
---------------------------------------
name = sngunfdq_xatryqbg_pnqvlgns
year = 1999
pass = PASS №873701
---------------------------------------
name = agkomohh_bxygkqvz_yhbeblab
year = 1999
pass = PASS №799526
---------------------------------------
name = byrcjlba_typoiuyz_kdsjtjnm
year = 1978
pass = PASS №72108
---------------------------------------
name = yfpnfdus_zjkmctcz_vxksabhw
year = 1978
pass = PASS №99600
---------------------------------------
name = scnbroxz_rvzbains_vdapoppt
year = 2012
pass = PASS №390560
---------------------------------------
name = apnstexp_ocpohgxg_esytykoc
year = 2012
pass = PASS №649061
---------------------------------------
name = bygmjbzm_dtlawebb_jmzbocbp
year = 1957
pass = PASS №734323
---------------------------------------
name = mduraorr_gelbrgka_tljsraox
year = 1991
pass = PASS №87393
---------------------------------------
name = eeecsval_adecfdho_dfgrpvue
year = 1991
pass = PASS №932136
---------------------------------------
name = sdvfcwkm_dkzwtwod_voemegbj
year = 1970
pass = PASS №941819
---------------------------------------
name = zhawelkf_vhgamyba_pqernbuv
year = 1970
pass = PASS №587088
---------------------------------------
name = mbtdudxy_wbusdoak_uprtkzut
year = 1970
pass = PASS №644678
---------------------------------------
name = crjijncn_vpbuwgls_onjvnvyg
year = 1970
pass = PASS №683326
---------------------------------------
name = fljydwqq_pckisppo_kcipojdc
year = 1983
pass = PASS №140405
---------------------------------------
name = lrnljrfn_ftxsyhxl_oytjcvro
year = 1983
pass = PASS №7634
---------------------------------------
name = dpsulsey_nozxubsc_jzmevkss
year = 1962
pass = PASS №672510
---------------------------------------
name = uyrqsnnv_shietsew_rwgeoovn
year = 1996
pass = PASS №228765
---------------------------------------
name = crisvhpc_tsyxsrrn_mpsucwdy
year = 1975
pass = PASS №309690
---------------------------------------
name = kkmidhlf_qrzxxqlo_dmszuztr
year = 1975
pass = PASS №792442
---------------------------------------
name = hretojkg_lvojpegm_ajphwkhc
year = 2009
pass = PASS №238067
---------------------------------------
name = znzajtmx_hvpzzdul_kxtzdfap
year = 2009
pass = PASS №401437
---------------------------------------
name = bvhvmeip_ceafktyj_poglcghw
year = 2009
pass = PASS №713070
---------------------------------------
name = ztjzpykg_rwhymsef_jrvazhqy
year = 1967
pass = PASS №470211
---------------------------------------
name = wewxznrl_rbjlenhc_xdanfprb
year = 2001
pass = PASS №70005
---------------------------------------
name = tbctxabb_poruxwvs_htxpygff
year = 2001
pass = PASS №101177
---------------------------------------
name = xeufjctg_hxjkmsjb_jtpehuaj
year = 2001
pass = PASS №207812
---------------------------------------
name = dkyybbbq_liutkckc_kxdomoan
year = 1980
pass = PASS №451071
---------------------------------------
name = blerxema_vjkoomsi_azojrnqp
year = 1980
pass = PASS №75040
---------------------------------------
name = jqqfxuiv_nyclmcnd_yhuicktn
year = 1959
pass = PASS №21356
---------------------------------------
name = rlrmlbek_cxcfhrpw_fvrdazna
year = 1993
pass = PASS №788318
---------------------------------------
name = khlgzkii_mttpltje_cceirkfq
year = 1993
pass = PASS №737843
---------------------------------------
name = cwvbiomp_ywldezmm_zoskapic
year = 1972
pass = PASS №133592
---------------------------------------
name = szivkjwl_zjtxujog_lhimrqqd
year = 1972
pass = PASS №347700
---------------------------------------
name = flldkhdo_iqvkpjkr_ikzejmhy
year = 1972
pass = PASS №983526
---------------------------------------
name = drudbghv_qpnkijne_jwaouxfn
year = 2006
pass = PASS №661401
---------------------------------------
name = vnajvvjf_qswixyrr_yuruwebe
year = 2006
pass = PASS №921635
---------------------------------------
name = frbnunaw_bxtnouzu_luthmeac
year = 1951
pass = PASS №398096
---------------------------------------
name = melmgkhx_goxdaopy_pntycomt
year = 1985
pass = PASS №565269
---------------------------------------
name = mqknwdac_dewqwtss_bnogxgto
year = 1985
pass = PASS №723144
---------------------------------------
name = etiolnbw_fdhodsez_wnqkvyuv
year = 1985
pass = PASS №334404
---------------------------------------
name = rjdgpxjk_cwqegvqf_gjtzgqqk
year = 1964
pass = PASS №95511
---------------------------------------
name = rtmigrbq_ewyhurbv_nctciisc
year = 2019
pass = PASS №772486
---------------------------------------
name = bdkohsva_xskumplz_cndujnrg
year = 1977
pass = PASS №498272
---------------------------------------
name = wwbjqvnd_kybztsws_grxektkm
year = 1977
pass = PASS №329268
---------------------------------------
name = xvhgllmr_rtvlyvoc_ehwxpacx
year = 1977
pass = PASS №703614
---------------------------------------
name = xhzhjole_ugnkgtor_euhczcnk
year = 1969
pass = PASS №160119
---------------------------------------
name = zzbnplxd_qrkjjcck_iclhtovl
year = 1969
pass = PASS №365238
---------------------------------------
name = mxvibupy_fmbmsmlj_jfitlcaa
year = 2003
pass = PASS №654848
---------------------------------------
name = kfddxdlu_obrnorpo_yvaejxja
year = 2003
pass = PASS №679737
---------------------------------------
name = zajwzmhp_zurpyhwq_gwwcmdbr
year = 2003
pass = PASS №908252
---------------------------------------
name = tncvocce_qzdxxfij_czzzqwwc
year = 1982
pass = PASS №72577
---------------------------------------
name = gmxklbgv_iyndvsid_fwcnwybn
year = 1982
pass = PASS №361701
---------------------------------------
name = abmriecn_iosyyuvr_imbxghiz
year = 2016
pass = PASS №233577
---------------------------------------
name = uyxugwqh_bftintfa_vtjnpoax
year = 2016
pass = PASS №764226
---------------------------------------
name = uzlrtico_hzlautbe_msccngax
year = 2016
pass = PASS №682508
---------------------------------------
name = kjgbxshc_gvgrxxtp_zzcmhajh
year = 1961
pass = PASS №870534
---------------------------------------
name = smosvqpe_mvktrmzt_kalcvaqd
year = 1961
pass = PASS №725346
---------------------------------------
name = rlnwsidz_viyhvuav_rlhbvqmj
year = 1974
pass = PASS №272875
---------------------------------------
name = qifiewtx_mhgbjjzm_vybjmhff
year = 1974
pass = PASS №238508
---------------------------------------
```
