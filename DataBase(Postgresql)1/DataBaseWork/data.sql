PGDMP         +                x            Odev    12.4    12.4 W    �           0    0    ENCODING    ENCODING        SET client_encoding = 'UTF8';
                      false            �           0    0 
   STDSTRINGS 
   STDSTRINGS     (   SET standard_conforming_strings = 'on';
                      false            �           0    0 
   SEARCHPATH 
   SEARCHPATH     8   SELECT pg_catalog.set_config('search_path', '', false);
                      false            �           1262    17761    Odev    DATABASE     �   CREATE DATABASE "Odev" WITH TEMPLATE = template0 ENCODING = 'UTF8' LC_COLLATE = 'English_United States.1252' LC_CTYPE = 'English_United States.1252';
    DROP DATABASE "Odev";
                postgres    false            �            1259    17762    adres    TABLE     �   CREATE TABLE public.adres (
    "adresNo" integer NOT NULL,
    ulke text NOT NULL,
    sehir text NOT NULL,
    ilce text NOT NULL,
    "acikAdres" text NOT NULL,
    "musteriNo" integer NOT NULL
);
    DROP TABLE public.adres;
       public         heap    postgres    false            �            1259    17768    dil    TABLE     V   CREATE TABLE public.dil (
    "dilNo" integer NOT NULL,
    "dilAdi" text NOT NULL
);
    DROP TABLE public.dil;
       public         heap    postgres    false            �            1259    17774    egitim    TABLE     �   CREATE TABLE public.egitim (
    "egitimNo" integer NOT NULL,
    "kursNo" integer NOT NULL,
    "ogretmenNo" integer NOT NULL
);
    DROP TABLE public.egitim;
       public         heap    postgres    false            �            1259    17777    egzersiz    TABLE     b   CREATE TABLE public.egzersiz (
    "dilNo" integer NOT NULL,
    "egzersizNo" integer NOT NULL
);
    DROP TABLE public.egzersiz;
       public         heap    postgres    false            �            1259    17780    kart    TABLE     �   CREATE TABLE public.kart (
    "kartNo" integer NOT NULL,
    "kartUzeriIsım" text NOT NULL,
    "sonKullanmaTarihi" text NOT NULL,
    "cvcNo" integer NOT NULL,
    "musteriNo" integer NOT NULL
);
    DROP TABLE public.kart;
       public         heap    postgres    false            �            1259    17786    kategori    TABLE     d   CREATE TABLE public.kategori (
    "kategoriNo" integer NOT NULL,
    "kategoriAd" text NOT NULL
);
    DROP TABLE public.kategori;
       public         heap    postgres    false            �            1259    17792    kayit    TABLE        CREATE TABLE public.kayit (
    "kayitNo" integer NOT NULL,
    "ogrenciNo" integer NOT NULL,
    "kursNo" integer NOT NULL
);
    DROP TABLE public.kayit;
       public         heap    postgres    false            �            1259    17795    kaynak    TABLE     ^   CREATE TABLE public.kaynak (
    "dilNo" integer NOT NULL,
    "kaynakNo" integer NOT NULL
);
    DROP TABLE public.kaynak;
       public         heap    postgres    false            �            1259    17798 
   konubaslik    TABLE     b   CREATE TABLE public.konubaslik (
    "dilNo" integer NOT NULL,
    "baslikNo" integer NOT NULL
);
    DROP TABLE public.konubaslik;
       public         heap    postgres    false            �            1259    17807 	   kullanici    TABLE     �   CREATE TABLE public.kullanici (
    "kullaniciNo" integer NOT NULL,
    ad text NOT NULL,
    soyad text NOT NULL,
    "telNo" bigint NOT NULL,
    sifre text NOT NULL,
    "mailAdres" text NOT NULL,
    "kullaniciTuru" text NOT NULL
);
    DROP TABLE public.kullanici;
       public         heap    postgres    false            �            1259    17801    kurs    TABLE     w   CREATE TABLE public.kurs (
    "kursNo" integer NOT NULL,
    "kursAdi" text NOT NULL,
    "dilNo" integer NOT NULL
);
    DROP TABLE public.kurs;
       public         heap    postgres    false            �            1259    18123    ogrenci    TABLE     {   CREATE TABLE public.ogrenci (
    "kullaniciNo" integer NOT NULL,
    bolum text NOT NULL,
    universite text NOT NULL
);
    DROP TABLE public.ogrenci;
       public         heap    postgres    false            �            1259    18136    ogretmen    TABLE     �   CREATE TABLE public.ogretmen (
    "kullaniciNo" integer NOT NULL,
    "universiteMezun" text NOT NULL,
    "verilenKursSayisi" integer NOT NULL,
    "sertifikaSayisi" integer NOT NULL,
    uzmanlik text NOT NULL
);
    DROP TABLE public.ogretmen;
       public         heap    postgres    false            �            1259    17825    quiz    TABLE     Z   CREATE TABLE public.quiz (
    "dilNo" integer NOT NULL,
    "quizNo" integer NOT NULL
);
    DROP TABLE public.quiz;
       public         heap    postgres    false            �            1259    17828 	   sertifika    TABLE     d   CREATE TABLE public.sertifika (
    "dilNo" integer NOT NULL,
    "sertifikaNo" integer NOT NULL
);
    DROP TABLE public.sertifika;
       public         heap    postgres    false            �            1259    17831    siparis    TABLE     }   CREATE TABLE public.siparis (
    "siparisNo" integer NOT NULL,
    tarih date NOT NULL,
    "musteriNo" integer NOT NULL
);
    DROP TABLE public.siparis;
       public         heap    postgres    false            �            1259    17834    siparisdetay    TABLE     �   CREATE TABLE public.siparisdetay (
    "siparisDetayNo" integer NOT NULL,
    "siparisNo" integer NOT NULL,
    "urunNo" integer NOT NULL
);
     DROP TABLE public.siparisdetay;
       public         heap    postgres    false            �            1259    17837    urun    TABLE     �   CREATE TABLE public.urun (
    "urunNo" integer NOT NULL,
    "urunAd" text NOT NULL,
    "urunBeden" integer NOT NULL,
    "urunRenk" text NOT NULL,
    "stokMiktar" integer NOT NULL,
    fiyat integer NOT NULL,
    "kategoriNo" integer NOT NULL
);
    DROP TABLE public.urun;
       public         heap    postgres    false            �          0    17762    adres 
   TABLE DATA           W   COPY public.adres ("adresNo", ulke, sehir, ilce, "acikAdres", "musteriNo") FROM stdin;
    public          postgres    false    202   �b       �          0    17768    dil 
   TABLE DATA           0   COPY public.dil ("dilNo", "dilAdi") FROM stdin;
    public          postgres    false    203   �c       �          0    17774    egitim 
   TABLE DATA           D   COPY public.egitim ("egitimNo", "kursNo", "ogretmenNo") FROM stdin;
    public          postgres    false    204   �c       �          0    17777    egzersiz 
   TABLE DATA           9   COPY public.egzersiz ("dilNo", "egzersizNo") FROM stdin;
    public          postgres    false    205   d       �          0    17780    kart 
   TABLE DATA           e   COPY public.kart ("kartNo", "kartUzeriIsım", "sonKullanmaTarihi", "cvcNo", "musteriNo") FROM stdin;
    public          postgres    false    206   Sd       �          0    17786    kategori 
   TABLE DATA           >   COPY public.kategori ("kategoriNo", "kategoriAd") FROM stdin;
    public          postgres    false    207   �d       �          0    17792    kayit 
   TABLE DATA           A   COPY public.kayit ("kayitNo", "ogrenciNo", "kursNo") FROM stdin;
    public          postgres    false    208   ?e       �          0    17795    kaynak 
   TABLE DATA           5   COPY public.kaynak ("dilNo", "kaynakNo") FROM stdin;
    public          postgres    false    209   �e       �          0    17798 
   konubaslik 
   TABLE DATA           9   COPY public.konubaslik ("dilNo", "baslikNo") FROM stdin;
    public          postgres    false    210   �e       �          0    17807 	   kullanici 
   TABLE DATA           k   COPY public.kullanici ("kullaniciNo", ad, soyad, "telNo", sifre, "mailAdres", "kullaniciTuru") FROM stdin;
    public          postgres    false    212   ,f       �          0    17801    kurs 
   TABLE DATA           <   COPY public.kurs ("kursNo", "kursAdi", "dilNo") FROM stdin;
    public          postgres    false    211   mg       �          0    18123    ogrenci 
   TABLE DATA           C   COPY public.ogrenci ("kullaniciNo", bolum, universite) FROM stdin;
    public          postgres    false    218   �g       �          0    18136    ogretmen 
   TABLE DATA           v   COPY public.ogretmen ("kullaniciNo", "universiteMezun", "verilenKursSayisi", "sertifikaSayisi", uzmanlik) FROM stdin;
    public          postgres    false    219   rh       �          0    17825    quiz 
   TABLE DATA           1   COPY public.quiz ("dilNo", "quizNo") FROM stdin;
    public          postgres    false    213   i       �          0    17828 	   sertifika 
   TABLE DATA           ;   COPY public.sertifika ("dilNo", "sertifikaNo") FROM stdin;
    public          postgres    false    214   Ni       �          0    17831    siparis 
   TABLE DATA           B   COPY public.siparis ("siparisNo", tarih, "musteriNo") FROM stdin;
    public          postgres    false    215   �i       �          0    17834    siparisdetay 
   TABLE DATA           O   COPY public.siparisdetay ("siparisDetayNo", "siparisNo", "urunNo") FROM stdin;
    public          postgres    false    216   �i       �          0    17837    urun 
   TABLE DATA           n   COPY public.urun ("urunNo", "urunAd", "urunBeden", "urunRenk", "stokMiktar", fiyat, "kategoriNo") FROM stdin;
    public          postgres    false    217   �i       �
           2606    17844    adres Adres_pkey 
   CONSTRAINT     W   ALTER TABLE ONLY public.adres
    ADD CONSTRAINT "Adres_pkey" PRIMARY KEY ("adresNo");
 <   ALTER TABLE ONLY public.adres DROP CONSTRAINT "Adres_pkey";
       public            postgres    false    202            �
           2606    17846    dil Dil_pkey 
   CONSTRAINT     Q   ALTER TABLE ONLY public.dil
    ADD CONSTRAINT "Dil_pkey" PRIMARY KEY ("dilNo");
 8   ALTER TABLE ONLY public.dil DROP CONSTRAINT "Dil_pkey";
       public            postgres    false    203            �
           2606    17848    egitim Egitim_pkey 
   CONSTRAINT     Z   ALTER TABLE ONLY public.egitim
    ADD CONSTRAINT "Egitim_pkey" PRIMARY KEY ("egitimNo");
 >   ALTER TABLE ONLY public.egitim DROP CONSTRAINT "Egitim_pkey";
       public            postgres    false    204            �
           2606    17850    egzersiz Egzersiz_pkey 
   CONSTRAINT     `   ALTER TABLE ONLY public.egzersiz
    ADD CONSTRAINT "Egzersiz_pkey" PRIMARY KEY ("egzersizNo");
 B   ALTER TABLE ONLY public.egzersiz DROP CONSTRAINT "Egzersiz_pkey";
       public            postgres    false    205            �
           2606    17852    kart Kart_pkey 
   CONSTRAINT     T   ALTER TABLE ONLY public.kart
    ADD CONSTRAINT "Kart_pkey" PRIMARY KEY ("kartNo");
 :   ALTER TABLE ONLY public.kart DROP CONSTRAINT "Kart_pkey";
       public            postgres    false    206            �
           2606    17854    kategori Kategori_pkey 
   CONSTRAINT     `   ALTER TABLE ONLY public.kategori
    ADD CONSTRAINT "Kategori_pkey" PRIMARY KEY ("kategoriNo");
 B   ALTER TABLE ONLY public.kategori DROP CONSTRAINT "Kategori_pkey";
       public            postgres    false    207            �
           2606    17856    kayit Kayit_pkey 
   CONSTRAINT     W   ALTER TABLE ONLY public.kayit
    ADD CONSTRAINT "Kayit_pkey" PRIMARY KEY ("kayitNo");
 <   ALTER TABLE ONLY public.kayit DROP CONSTRAINT "Kayit_pkey";
       public            postgres    false    208            �
           2606    17858    kaynak Kaynak_pkey 
   CONSTRAINT     Z   ALTER TABLE ONLY public.kaynak
    ADD CONSTRAINT "Kaynak_pkey" PRIMARY KEY ("kaynakNo");
 >   ALTER TABLE ONLY public.kaynak DROP CONSTRAINT "Kaynak_pkey";
       public            postgres    false    209            �
           2606    17860    konubaslik KonuBaslik_Pkey 
   CONSTRAINT     b   ALTER TABLE ONLY public.konubaslik
    ADD CONSTRAINT "KonuBaslik_Pkey" PRIMARY KEY ("baslikNo");
 F   ALTER TABLE ONLY public.konubaslik DROP CONSTRAINT "KonuBaslik_Pkey";
       public            postgres    false    210            �
           2606    17862    kurs Kurs_pkey 
   CONSTRAINT     T   ALTER TABLE ONLY public.kurs
    ADD CONSTRAINT "Kurs_pkey" PRIMARY KEY ("kursNo");
 :   ALTER TABLE ONLY public.kurs DROP CONSTRAINT "Kurs_pkey";
       public            postgres    false    211            �
           2606    17864    kullanici Musteri_pkey 
   CONSTRAINT     a   ALTER TABLE ONLY public.kullanici
    ADD CONSTRAINT "Musteri_pkey" PRIMARY KEY ("kullaniciNo");
 B   ALTER TABLE ONLY public.kullanici DROP CONSTRAINT "Musteri_pkey";
       public            postgres    false    212            �
           2606    17870    quiz Quiz_pkey 
   CONSTRAINT     T   ALTER TABLE ONLY public.quiz
    ADD CONSTRAINT "Quiz_pkey" PRIMARY KEY ("quizNo");
 :   ALTER TABLE ONLY public.quiz DROP CONSTRAINT "Quiz_pkey";
       public            postgres    false    213            �
           2606    17872    sertifika Sertifika_pkey 
   CONSTRAINT     c   ALTER TABLE ONLY public.sertifika
    ADD CONSTRAINT "Sertifika_pkey" PRIMARY KEY ("sertifikaNo");
 D   ALTER TABLE ONLY public.sertifika DROP CONSTRAINT "Sertifika_pkey";
       public            postgres    false    214            �
           2606    17874    siparisdetay SiparisDetay_pkey 
   CONSTRAINT     l   ALTER TABLE ONLY public.siparisdetay
    ADD CONSTRAINT "SiparisDetay_pkey" PRIMARY KEY ("siparisDetayNo");
 J   ALTER TABLE ONLY public.siparisdetay DROP CONSTRAINT "SiparisDetay_pkey";
       public            postgres    false    216            �
           2606    17876    siparis Siparis_pkey 
   CONSTRAINT     ]   ALTER TABLE ONLY public.siparis
    ADD CONSTRAINT "Siparis_pkey" PRIMARY KEY ("siparisNo");
 @   ALTER TABLE ONLY public.siparis DROP CONSTRAINT "Siparis_pkey";
       public            postgres    false    215            �
           2606    17878    urun Urun_pkey 
   CONSTRAINT     T   ALTER TABLE ONLY public.urun
    ADD CONSTRAINT "Urun_pkey" PRIMARY KEY ("urunNo");
 :   ALTER TABLE ONLY public.urun DROP CONSTRAINT "Urun_pkey";
       public            postgres    false    217            �
           2606    17880    kullanici mail_Unique 
   CONSTRAINT     Y   ALTER TABLE ONLY public.kullanici
    ADD CONSTRAINT "mail_Unique" UNIQUE ("mailAdres");
 A   ALTER TABLE ONLY public.kullanici DROP CONSTRAINT "mail_Unique";
       public            postgres    false    212            �
           2606    18130    ogrenci ogrenci_pkey 
   CONSTRAINT     ]   ALTER TABLE ONLY public.ogrenci
    ADD CONSTRAINT ogrenci_pkey PRIMARY KEY ("kullaniciNo");
 >   ALTER TABLE ONLY public.ogrenci DROP CONSTRAINT ogrenci_pkey;
       public            postgres    false    218            �
           2606    18143    ogretmen ogretmen_pkey 
   CONSTRAINT     _   ALTER TABLE ONLY public.ogretmen
    ADD CONSTRAINT ogretmen_pkey PRIMARY KEY ("kullaniciNo");
 @   ALTER TABLE ONLY public.ogretmen DROP CONSTRAINT ogretmen_pkey;
       public            postgres    false    219            �
           1259    17883    fki_dilNo_FK    INDEX     B   CREATE INDEX "fki_dilNo_FK" ON public.kurs USING btree ("dilNo");
 "   DROP INDEX public."fki_dilNo_FK";
       public            postgres    false    211            �
           1259    17884    fki_kategoriNo_FK    INDEX     L   CREATE INDEX "fki_kategoriNo_FK" ON public.urun USING btree ("kategoriNo");
 '   DROP INDEX public."fki_kategoriNo_FK";
       public            postgres    false    217            �
           1259    17885    fki_kursNo_FK    INDEX     E   CREATE INDEX "fki_kursNo_FK" ON public.kayit USING btree ("kursNo");
 #   DROP INDEX public."fki_kursNo_FK";
       public            postgres    false    208            �
           1259    17886    fki_musteriNO_FK    INDEX     K   CREATE INDEX "fki_musteriNO_FK" ON public.adres USING btree ("musteriNo");
 &   DROP INDEX public."fki_musteriNO_FK";
       public            postgres    false    202            �
           1259    17887    fki_musteriNo    INDEX     D   CREATE INDEX "fki_musteriNo" ON public.kurs USING btree ("kursNo");
 #   DROP INDEX public."fki_musteriNo";
       public            postgres    false    211            �
           1259    17888    fki_musteriNo_FK    INDEX     M   CREATE INDEX "fki_musteriNo_FK" ON public.siparis USING btree ("musteriNo");
 &   DROP INDEX public."fki_musteriNo_FK";
       public            postgres    false    215            �
           1259    18014    fki_ogrenci_FK    INDEX     I   CREATE INDEX "fki_ogrenci_FK" ON public.kayit USING btree ("ogrenciNo");
 $   DROP INDEX public."fki_ogrenci_FK";
       public            postgres    false    208            �
           1259    17990    fki_ogretmen_FK    INDEX     L   CREATE INDEX "fki_ogretmen_FK" ON public.egitim USING btree ("ogretmenNo");
 %   DROP INDEX public."fki_ogretmen_FK";
       public            postgres    false    204            �
           1259    17889    fki_siparis_No_FK    INDEX     S   CREATE INDEX "fki_siparis_No_FK" ON public.siparisdetay USING btree ("siparisNo");
 '   DROP INDEX public."fki_siparis_No_FK";
       public            postgres    false    216            �
           1259    17890    fki_urunNO_FK    INDEX     L   CREATE INDEX "fki_urunNO_FK" ON public.siparisdetay USING btree ("urunNo");
 #   DROP INDEX public."fki_urunNO_FK";
       public            postgres    false    216                       2606    17891 
   quiz dilNo    FK CONSTRAINT     x   ALTER TABLE ONLY public.quiz
    ADD CONSTRAINT "dilNo" FOREIGN KEY ("dilNo") REFERENCES public.dil("dilNo") NOT VALID;
 6   ALTER TABLE ONLY public.quiz DROP CONSTRAINT "dilNo";
       public          postgres    false    203    213    2766            �
           2606    17896    egzersiz dilNo    FK CONSTRAINT     |   ALTER TABLE ONLY public.egzersiz
    ADD CONSTRAINT "dilNo" FOREIGN KEY ("dilNo") REFERENCES public.dil("dilNo") NOT VALID;
 :   ALTER TABLE ONLY public.egzersiz DROP CONSTRAINT "dilNo";
       public          postgres    false    2766    203    205                       2606    17901    konubaslik dilNo    FK CONSTRAINT     ~   ALTER TABLE ONLY public.konubaslik
    ADD CONSTRAINT "dilNo" FOREIGN KEY ("dilNo") REFERENCES public.dil("dilNo") NOT VALID;
 <   ALTER TABLE ONLY public.konubaslik DROP CONSTRAINT "dilNo";
       public          postgres    false    2766    203    210                       2606    17906    sertifika dilNo    FK CONSTRAINT     }   ALTER TABLE ONLY public.sertifika
    ADD CONSTRAINT "dilNo" FOREIGN KEY ("dilNo") REFERENCES public.dil("dilNo") NOT VALID;
 ;   ALTER TABLE ONLY public.sertifika DROP CONSTRAINT "dilNo";
       public          postgres    false    2766    214    203                       2606    17911    kaynak dilNo    FK CONSTRAINT     z   ALTER TABLE ONLY public.kaynak
    ADD CONSTRAINT "dilNo" FOREIGN KEY ("dilNo") REFERENCES public.dil("dilNo") NOT VALID;
 8   ALTER TABLE ONLY public.kaynak DROP CONSTRAINT "dilNo";
       public          postgres    false    209    203    2766                       2606    17916    kurs dilNo_FK    FK CONSTRAINT     {   ALTER TABLE ONLY public.kurs
    ADD CONSTRAINT "dilNo_FK" FOREIGN KEY ("dilNo") REFERENCES public.dil("dilNo") NOT VALID;
 9   ALTER TABLE ONLY public.kurs DROP CONSTRAINT "dilNo_FK";
       public          postgres    false    2766    211    203            	           2606    17921    urun kategoriNo_FK    FK CONSTRAINT     �   ALTER TABLE ONLY public.urun
    ADD CONSTRAINT "kategoriNo_FK" FOREIGN KEY ("kategoriNo") REFERENCES public.kategori("kategoriNo") NOT VALID;
 >   ALTER TABLE ONLY public.urun DROP CONSTRAINT "kategoriNo_FK";
       public          postgres    false    217    207    2775                        2606    18164    kayit kursNo_FK    FK CONSTRAINT     �   ALTER TABLE ONLY public.kayit
    ADD CONSTRAINT "kursNo_FK" FOREIGN KEY ("kursNo") REFERENCES public.kurs("kursNo") ON UPDATE CASCADE ON DELETE CASCADE NOT VALID;
 ;   ALTER TABLE ONLY public.kayit DROP CONSTRAINT "kursNo_FK";
       public          postgres    false    208    211    2785            �
           2606    18174    egitim kursNo_FK    FK CONSTRAINT     �   ALTER TABLE ONLY public.egitim
    ADD CONSTRAINT "kursNo_FK" FOREIGN KEY ("kursNo") REFERENCES public.kurs("kursNo") ON UPDATE CASCADE ON DELETE CASCADE NOT VALID;
 <   ALTER TABLE ONLY public.egitim DROP CONSTRAINT "kursNo_FK";
       public          postgres    false    211    2785    204            �
           2606    17936    adres musteriNO_FK    FK CONSTRAINT     �   ALTER TABLE ONLY public.adres
    ADD CONSTRAINT "musteriNO_FK" FOREIGN KEY ("musteriNo") REFERENCES public.kullanici("kullaniciNo") NOT VALID;
 >   ALTER TABLE ONLY public.adres DROP CONSTRAINT "musteriNO_FK";
       public          postgres    false    212    2789    202                       2606    17941    siparis musteriNo_FK    FK CONSTRAINT     �   ALTER TABLE ONLY public.siparis
    ADD CONSTRAINT "musteriNo_FK" FOREIGN KEY ("musteriNo") REFERENCES public.kullanici("kullaniciNo") NOT VALID;
 @   ALTER TABLE ONLY public.siparis DROP CONSTRAINT "musteriNo_FK";
       public          postgres    false    215    212    2789            �
           2606    17946    kart musteriNo_FK    FK CONSTRAINT     �   ALTER TABLE ONLY public.kart
    ADD CONSTRAINT "musteriNo_FK" FOREIGN KEY ("musteriNo") REFERENCES public.kullanici("kullaniciNo") NOT VALID;
 =   ALTER TABLE ONLY public.kart DROP CONSTRAINT "musteriNo_FK";
       public          postgres    false    2789    206    212            
           2606    18131    ogrenci ogrenciNo_FK    FK CONSTRAINT     �   ALTER TABLE ONLY public.ogrenci
    ADD CONSTRAINT "ogrenciNo_FK" FOREIGN KEY ("kullaniciNo") REFERENCES public.kullanici("kullaniciNo") ON UPDATE CASCADE ON DELETE CASCADE NOT VALID;
 @   ALTER TABLE ONLY public.ogrenci DROP CONSTRAINT "ogrenciNo_FK";
       public          postgres    false    212    218    2789            �
           2606    18159    kayit ogrenci_FK    FK CONSTRAINT     �   ALTER TABLE ONLY public.kayit
    ADD CONSTRAINT "ogrenci_FK" FOREIGN KEY ("ogrenciNo") REFERENCES public.ogrenci("kullaniciNo") ON UPDATE CASCADE ON DELETE CASCADE NOT VALID;
 <   ALTER TABLE ONLY public.kayit DROP CONSTRAINT "ogrenci_FK";
       public          postgres    false    2807    208    218                       2606    18144    ogretmen ogretmen_FK    FK CONSTRAINT     �   ALTER TABLE ONLY public.ogretmen
    ADD CONSTRAINT "ogretmen_FK" FOREIGN KEY ("kullaniciNo") REFERENCES public.kullanici("kullaniciNo") ON UPDATE CASCADE ON DELETE CASCADE NOT VALID;
 @   ALTER TABLE ONLY public.ogretmen DROP CONSTRAINT "ogretmen_FK";
       public          postgres    false    2789    212    219            �
           2606    18169    egitim ogretmen_FK    FK CONSTRAINT     �   ALTER TABLE ONLY public.egitim
    ADD CONSTRAINT "ogretmen_FK" FOREIGN KEY ("ogretmenNo") REFERENCES public.ogretmen("kullaniciNo") ON UPDATE CASCADE ON DELETE CASCADE NOT VALID;
 >   ALTER TABLE ONLY public.egitim DROP CONSTRAINT "ogretmen_FK";
       public          postgres    false    219    2809    204                       2606    17966    siparisdetay siparis_No_FK    FK CONSTRAINT     �   ALTER TABLE ONLY public.siparisdetay
    ADD CONSTRAINT "siparis_No_FK" FOREIGN KEY ("siparisNo") REFERENCES public.siparis("siparisNo") NOT VALID;
 F   ALTER TABLE ONLY public.siparisdetay DROP CONSTRAINT "siparis_No_FK";
       public          postgres    false    215    2797    216                       2606    17971    siparisdetay urunNO_FK    FK CONSTRAINT     �   ALTER TABLE ONLY public.siparisdetay
    ADD CONSTRAINT "urunNO_FK" FOREIGN KEY ("urunNo") REFERENCES public.urun("urunNo") NOT VALID;
 B   ALTER TABLE ONLY public.siparisdetay DROP CONSTRAINT "urunNO_FK";
       public          postgres    false    2804    217    216            �   �   x�m�A�0EםS�	����7iZ�iKb��k� �����?���G��q�F�F���`���C�@��q�'{��1B%p��`p���%���T}�{�Zp�V�,�su��&hN?�\$��68�~�!m�M�����|�������ą�} ,YeD      �   (   x�3�L���2�LV�2��J,K�2�,�,�������� rEB      �   2   x��� !����S	���׌u��Y�jv\:�Ll�8���}�ێ�      �   <   x�Ĺ�0�Z&gJ���#d0FJI�Dƒ-G�p��t�ʵ���r�wU��E�M      �   �   x�5�K
�0DףS�����]���%Ц�4���.��=f$f�ױ�eJb�b�������e�����Xp9�����_Ȗ�4�9�Z�Z}Yǎ�g�Nb^j��g�1G�����V�glK�Ȝ$NX<�I#b�%Q���&"�P�,      �   :   x�3�,H�+�����2�,.OM,�2�<:?� ;�˄3;�*1�˔�D�8���+F��� ��      �   <   x��� !���	�O/�_Ǣ9=Yr(tZ#m�m2���tO��`i?�m�c;�<�~�"      �   -   x���  ���DB�z��:�H
B�T�����C�zt^>���      �   T   x���1�7��p4�\�qh���R�2��ȕ'�<-�����6��T./ˠ����M�.=U��*(��ihӡKO������-�      �   1  x�mR�n�0}6S-	��m���� AA���s��*A����>A��)B�q��1��M���ɩ~��r[=�C�p�*	G�_ܦ���X��q��I(��}D暑~�3f��X'����9U�7��)T5l�#L�0� �|J�p����7nL���u5��n<���H����9�Z׺V���-۱�c3F�<�eV�H�c�����D�Qq~N�G�ݤ�ᯨ@W�G1�;��mŬ�^?|�Ô�}��@�6�
�o�Cs�o"�r̛])����l��Ճ0�i��5����TU�E��      �   j   x��I
�0�/��R�8-���G�4�ƁB�U�qWTQ�s�U�ƌ����UhqI��ģ��X�;�y�bmL����U���$���J�Gܿ�k�J���� L��      �   {   x���A
�0��+��B{h��^"�E��]p~�?�a�GCC�;��5�	N�,-u�<����5J5���(숷�h�b�Yx�<TM�%Cz�XY��������Q�7�m�Yy�j����K�� ��`�      �   �   x�u��
�0���S<��T�x��"kb�IZ�Oo=I@��|cQ8p�X-I�)�S��������zH���%�:�$�e{Uy�$4|y��r��Y�I��I�����_��3�0���g�g�ˑ����H4      �   8   x����@�7�	�����:I����´e���&�J�ʹ�N']~�ю
�      �   "   x�3�4400�2�4QƜ� ʄ�D��qqq T	�      �      x�34 CN##]C#] Ӑ+F��� 8S�      �      x�3400�440 S&\1z\\\ &�F      �   �   x�e�OJ1�׿���$/��Y��j]�k��3L�)��L/�����Ĥ� d�xߗ�ߋ ������b�ގ��_LA�H&���&)1����v���N����7 �W��#T݀�lW �O�"�:�u���J����4ٹ	�M3He�yF������U&H!�3����gP�cɲ��ʀ�o#Oɤ�����}��t�a�?���s�������+M}2�ll7�F�%x��h�b���O�Ԩ9{�f��"�pU     