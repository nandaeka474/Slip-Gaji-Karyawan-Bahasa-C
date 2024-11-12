#include <stdio.h>

int hitungPPH21Tahunan(float gaji_kena_pajak)
{
    int pph21_tahunan = 0;

    if (gaji_kena_pajak < 0){
        return pph21_tahunan;
    }

    if (gaji_kena_pajak > 60000000)
    {
        pph21_tahunan += 60000000 *0.05;
        gaji_kena_pajak -= 60000000;
    }
    else
    {
        pph21_tahunan += gaji_kena_pajak *0.05;
        return pph21_tahunan;
    }

    if (gaji_kena_pajak > 250000000)
    {
        pph21_tahunan += 250000000 *0.15;
        gaji_kena_pajak -= 250000000;
    }
    else
    {
        pph21_tahunan += gaji_kena_pajak *0.15;
        return pph21_tahunan;
    }

    if (gaji_kena_pajak > 500000000)
    {
        pph21_tahunan = 500000000 *0.25;
        gaji_kena_pajak -= 500000000;
    }
    else
    {
        pph21_tahunan += gaji_kena_pajak *0.25;
        return pph21_tahunan;
    }

    return pph21_tahunan;

}


float hitungLembur(int lama_kerja, float gaji_per_jam)
{
    if (lama_kerja > 155)
    {
        return (float)(lama_kerja-155)*1.5*gaji_per_jam;
    }

    return 0;
}


float hitungGaji(int lama_kerja, float gaji_pokok, float gaji_per_jam)
{
    if (lama_kerja >= 155)
    {
        return gaji_pokok;
    }

    return (gaji_per_jam*lama_kerja);
}

int main()
{
    // Deklarasi variabel
    char nama_pt[50] = "PT. ABC";
    char nama[50];
    char* jabatan;
    int golongan,lama_kerja ;
    float gaji_pokok, lembur,gaji_per_jam, gaji_tanpa_lembur, gaji_bersih;
    float gaji_dipotong_jabatan, gaji_bersih_setahun,gaji_kena_pajak, pph21_setahun, pph21_sebulan;


    printf("****************** Payrol PT. ABC ******************\n", nama_pt);
    printf("====================================================\n");
    // Input data karyawan
    printf("Masukkan nama karyawan                  : ");
    scanf("%[^\n]", nama);
    printf("Masukkan golongan (1-4)                 : ");
    scanf("%d", &golongan);
    printf("Masukkan jumlah jam kerja (1 bulan/jam) : ");
    scanf("%d", &lama_kerja);
    printf("\n\n");
    printf("====================================================\n");


    // Hitung gaji pokok
    switch (golongan)
    {
    case 1:
        jabatan = "Operator";
        gaji_pokok = 3000000;
        gaji_per_jam = 3000;

        break;
    case 2:
        jabatan = "Supervisor";
        gaji_pokok = 5000000;
        gaji_per_jam = 5000;

        break;
    case 3:

        jabatan = "Manajer";
        gaji_pokok = 8000000;
        gaji_per_jam = 8000;

        break;
    case 4:
        jabatan = "Direktur";
        gaji_pokok = 10000000;
        gaji_per_jam = 10000;

        break;
    default:
        printf("Golongan yang dimasukkan tidak valid.\n");
        return 0;
    }

    lembur = hitungLembur(lama_kerja,gaji_per_jam);
    gaji_tanpa_lembur = hitungGaji( lama_kerja,  gaji_pokok,  gaji_per_jam);
    gaji_dipotong_jabatan = (gaji_tanpa_lembur+lembur)- ((gaji_tanpa_lembur+lembur)*0.05); //gaji sebulan yang sudah dikurangin dengan biaya jabatan sebsar 5% dari total gaji
    gaji_bersih_setahun = gaji_dipotong_jabatan * 12;
    gaji_kena_pajak = gaji_bersih_setahun - 54000000;//ptkp
    pph21_setahun = hitungPPH21Tahunan(gaji_kena_pajak);
    pph21_sebulan = pph21_setahun / 12;
    gaji_bersih = (gaji_tanpa_lembur + lembur) - pph21_sebulan;

    // Output gaji karyawan
    printf("******************************************************\n");
    printf("                   SLIP GAJI KARYAWAN                 \n");
    printf("******************************************************\n");
    printf("%s \n", nama_pt);
    printf("Jl Jendral Sudirman Kav 29\n");
    printf("Kuningan, DKI Jakarta");
    printf("         ");
    printf("Tanggal     : 25/06/2023\n");
    printf("******************************************************\n");
    printf("Nama        : %s \n", nama);
    printf("Jabatan     : %s \n", jabatan);
    printf("======================================================\n");
    printf("Gaji Pokok                          : Rp. %.2f\n", gaji_tanpa_lembur);
    printf("Gaji Lembur                         : Rp. %.2f\n", lembur);
    printf("Ditanggung karyawan (-) \n");
    printf("PPH21                               : Rp. %.2f\n", pph21_sebulan);
    printf("======================================================\n");
    printf("Gaji bersih                       : Rp. %.2f\n", gaji_bersih);


    return 0;
}
