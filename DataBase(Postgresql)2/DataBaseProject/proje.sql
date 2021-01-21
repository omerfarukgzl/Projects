--
-- PostgreSQL database dump
--

-- Dumped from database version 12.4
-- Dumped by pg_dump version 12.4

-- Started on 2020-12-30 12:12:37

SET statement_timeout = 0;
SET lock_timeout = 0;
SET idle_in_transaction_session_timeout = 0;
SET client_encoding = 'UTF8';
SET standard_conforming_strings = on;
SELECT pg_catalog.set_config('search_path', '', false);
SET check_function_bodies = false;
SET xmloption = content;
SET client_min_messages = warning;
SET row_security = off;

--
-- TOC entry 268 (class 1255 OID 19452)
-- Name: kayit_sirala_ogretmen(integer); Type: FUNCTION; Schema: public; Owner: postgres
--

CREATE FUNCTION public.kayit_sirala_ogretmen(ogretmen integer) RETURNS TABLE(ozeldersid integer)
    LANGUAGE sql
    AS $$
 select ozeldersid from ozelders where ogretmenid = ogretmen; 
$$;


ALTER FUNCTION public.kayit_sirala_ogretmen(ogretmen integer) OWNER TO postgres;

--
-- TOC entry 270 (class 1255 OID 19466)
-- Name: ogrenci_kayit(text, text, text, integer, integer, text, text); Type: PROCEDURE; Schema: public; Owner: postgres
--

CREATE PROCEDURE public.ogrenci_kayit(ad text, soyad text, kullaniciad text, sifre integer, yas integer, cinsiyet text, kullanici text)
    LANGUAGE plpgsql
    AS $$
begin 
insert into kullanici values(DEFAULT,ad,soyad,kullaniciad,sifre,yas,cinsiyet,kullanici);
END;
$$;


ALTER PROCEDURE public.ogrenci_kayit(ad text, soyad text, kullaniciad text, sifre integer, yas integer, cinsiyet text, kullanici text) OWNER TO postgres;

--
-- TOC entry 267 (class 1255 OID 19450)
-- Name: ogrenci_kayitsirala(integer); Type: FUNCTION; Schema: public; Owner: postgres
--

CREATE FUNCTION public.ogrenci_kayitsirala(ogrenci integer) RETURNS TABLE(ozeldersid integer)
    LANGUAGE sql
    AS $$
    select ozeldersid from ozelders where ogrenciid =ogrenci; 
$$;


ALTER FUNCTION public.ogrenci_kayitsirala(ogrenci integer) OWNER TO postgres;

--
-- TOC entry 250 (class 1255 OID 19421)
-- Name: ozel_ders_ekle(integer, integer, integer, integer, integer); Type: PROCEDURE; Schema: public; Owner: postgres
--

CREATE PROCEDURE public.ozel_ders_ekle(dershane integer, bolum integer, ders integer, ogretmen integer, ogrenci integer)
    LANGUAGE plpgsql
    AS $$
begin 
insert into ozelders values(DEFAULT,dershane,bolum,ders,ogretmen,ogrenci);
END;
$$;


ALTER PROCEDURE public.ozel_ders_ekle(dershane integer, bolum integer, ders integer, ogretmen integer, ogrenci integer) OWNER TO postgres;

--
-- TOC entry 249 (class 1255 OID 19423)
-- Name: ozel_ders_sil(integer); Type: PROCEDURE; Schema: public; Owner: postgres
--

CREATE PROCEDURE public.ozel_ders_sil(kayit integer)
    LANGUAGE plpgsql
    AS $$
begin 
delete from ozelders Where ozeldersid = kayit;
END;
$$;


ALTER PROCEDURE public.ozel_ders_sil(kayit integer) OWNER TO postgres;

--
-- TOC entry 251 (class 1255 OID 19424)
-- Name: siparis_ekle(integer, integer); Type: PROCEDURE; Schema: public; Owner: postgres
--

CREATE PROCEDURE public.siparis_ekle(ogrenciid integer, kitapid integer)
    LANGUAGE plpgsql
    AS $$
begin 
insert into siparis values(DEFAULT,ogrenciid,kitapid);
END;
$$;


ALTER PROCEDURE public.siparis_ekle(ogrenciid integer, kitapid integer) OWNER TO postgres;

--
-- TOC entry 271 (class 1255 OID 19467)
-- Name: siparis_sil(integer); Type: PROCEDURE; Schema: public; Owner: postgres
--

CREATE PROCEDURE public.siparis_sil(siparis_id integer)
    LANGUAGE plpgsql
    AS $$
begin 
delete from siparis where siparisid=siparis_id;
END;
$$;


ALTER PROCEDURE public.siparis_sil(siparis_id integer) OWNER TO postgres;

--
-- TOC entry 254 (class 1255 OID 19435)
-- Name: stok(); Type: FUNCTION; Schema: public; Owner: postgres
--

CREATE FUNCTION public.stok() RETURNS trigger
    LANGUAGE plpgsql
    AS $$
declare
kitapsiparis integer;
begin
kitapsiparis:=(select kitapid from siparis order by siparisid desc limit 1);
update kitap set stokmiktari=stokmiktari-1 where kitapid=kitapsiparis;
return new;
end;
$$;


ALTER FUNCTION public.stok() OWNER TO postgres;

--
-- TOC entry 269 (class 1255 OID 19438)
-- Name: stok2(); Type: FUNCTION; Schema: public; Owner: postgres
--

CREATE FUNCTION public.stok2() RETURNS trigger
    LANGUAGE plpgsql
    AS $$
declare
kitapsiparis integer;
begin
update kitap set stokmiktari=stokmiktari+1 where kitapid=OLD.kitapid;
return new;
end;
$$;


ALTER FUNCTION public.stok2() OWNER TO postgres;

--
-- TOC entry 252 (class 1255 OID 19428)
-- Name: toplam(); Type: FUNCTION; Schema: public; Owner: postgres
--

CREATE FUNCTION public.toplam() RETURNS trigger
    LANGUAGE plpgsql
    AS $$
begin
update toplam_kullanici set toplam=toplam+1;
return new;
end;
$$;


ALTER FUNCTION public.toplam() OWNER TO postgres;

--
-- TOC entry 253 (class 1255 OID 19430)
-- Name: toplam2(); Type: FUNCTION; Schema: public; Owner: postgres
--

CREATE FUNCTION public.toplam2() RETURNS trigger
    LANGUAGE plpgsql
    AS $$
begin
update toplam_kullanici set toplam=toplam-1;
return new;
end;
$$;


ALTER FUNCTION public.toplam2() OWNER TO postgres;

SET default_tablespace = '';

SET default_table_access_method = heap;

--
-- TOC entry 203 (class 1259 OID 18945)
-- Name: bolum; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.bolum (
    bolumid integer NOT NULL,
    bolumadi text
);


ALTER TABLE public.bolum OWNER TO postgres;

--
-- TOC entry 202 (class 1259 OID 18943)
-- Name: bolum_bolumID_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public."bolum_bolumID_seq"
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public."bolum_bolumID_seq" OWNER TO postgres;

--
-- TOC entry 3104 (class 0 OID 0)
-- Dependencies: 202
-- Name: bolum_bolumID_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public."bolum_bolumID_seq" OWNED BY public.bolum.bolumid;


--
-- TOC entry 229 (class 1259 OID 19177)
-- Name: bolum_dershane; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.bolum_dershane (
    bolumid integer NOT NULL,
    dershaneid integer NOT NULL
);


ALTER TABLE public.bolum_dershane OWNER TO postgres;

--
-- TOC entry 227 (class 1259 OID 19173)
-- Name: bolum_dershane_bolumID_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public."bolum_dershane_bolumID_seq"
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public."bolum_dershane_bolumID_seq" OWNER TO postgres;

--
-- TOC entry 3105 (class 0 OID 0)
-- Dependencies: 227
-- Name: bolum_dershane_bolumID_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public."bolum_dershane_bolumID_seq" OWNED BY public.bolum_dershane.bolumid;


--
-- TOC entry 228 (class 1259 OID 19175)
-- Name: bolum_dershane_dershaneID_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public."bolum_dershane_dershaneID_seq"
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public."bolum_dershane_dershaneID_seq" OWNER TO postgres;

--
-- TOC entry 3106 (class 0 OID 0)
-- Dependencies: 228
-- Name: bolum_dershane_dershaneID_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public."bolum_dershane_dershaneID_seq" OWNED BY public.bolum_dershane.dershaneid;


--
-- TOC entry 235 (class 1259 OID 19222)
-- Name: ders; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.ders (
    dersid integer NOT NULL,
    dersadi text,
    bolumid integer NOT NULL
);


ALTER TABLE public.ders OWNER TO postgres;

--
-- TOC entry 234 (class 1259 OID 19220)
-- Name: ders_bolumID_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public."ders_bolumID_seq"
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public."ders_bolumID_seq" OWNER TO postgres;

--
-- TOC entry 3107 (class 0 OID 0)
-- Dependencies: 234
-- Name: ders_bolumID_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public."ders_bolumID_seq" OWNED BY public.ders.bolumid;


--
-- TOC entry 233 (class 1259 OID 19218)
-- Name: ders_dersID_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public."ders_dersID_seq"
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public."ders_dersID_seq" OWNER TO postgres;

--
-- TOC entry 3108 (class 0 OID 0)
-- Dependencies: 233
-- Name: ders_dersID_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public."ders_dersID_seq" OWNED BY public.ders.dersid;


--
-- TOC entry 214 (class 1259 OID 19009)
-- Name: dershane; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.dershane (
    dershaneid integer NOT NULL,
    dershaneadi text,
    dershanetur text,
    dershanesubesayisi integer,
    dershaneadresid integer NOT NULL
);


ALTER TABLE public.dershane OWNER TO postgres;

--
-- TOC entry 213 (class 1259 OID 19007)
-- Name: dershane_dershaneAdresID_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public."dershane_dershaneAdresID_seq"
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public."dershane_dershaneAdresID_seq" OWNER TO postgres;

--
-- TOC entry 3109 (class 0 OID 0)
-- Dependencies: 213
-- Name: dershane_dershaneAdresID_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public."dershane_dershaneAdresID_seq" OWNED BY public.dershane.dershaneadresid;


--
-- TOC entry 212 (class 1259 OID 19005)
-- Name: dershane_dershaneID_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public."dershane_dershaneID_seq"
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public."dershane_dershaneID_seq" OWNER TO postgres;

--
-- TOC entry 3110 (class 0 OID 0)
-- Dependencies: 212
-- Name: dershane_dershaneID_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public."dershane_dershaneID_seq" OWNED BY public.dershane.dershaneid;


--
-- TOC entry 211 (class 1259 OID 18989)
-- Name: dershaneadres; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.dershaneadres (
    adresid integer NOT NULL,
    ilceid integer NOT NULL,
    detay text
);


ALTER TABLE public.dershaneadres OWNER TO postgres;

--
-- TOC entry 209 (class 1259 OID 18985)
-- Name: dershaneadres_adresID_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public."dershaneadres_adresID_seq"
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public."dershaneadres_adresID_seq" OWNER TO postgres;

--
-- TOC entry 3111 (class 0 OID 0)
-- Dependencies: 209
-- Name: dershaneadres_adresID_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public."dershaneadres_adresID_seq" OWNED BY public.dershaneadres.adresid;


--
-- TOC entry 210 (class 1259 OID 18987)
-- Name: dershaneadres_ilceID_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public."dershaneadres_ilceID_seq"
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public."dershaneadres_ilceID_seq" OWNER TO postgres;

--
-- TOC entry 3112 (class 0 OID 0)
-- Dependencies: 210
-- Name: dershaneadres_ilceID_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public."dershaneadres_ilceID_seq" OWNED BY public.dershaneadres.ilceid;


--
-- TOC entry 208 (class 1259 OID 18969)
-- Name: ilce; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.ilce (
    ilceid integer NOT NULL,
    sehirid integer NOT NULL,
    ilcead text
);


ALTER TABLE public.ilce OWNER TO postgres;

--
-- TOC entry 206 (class 1259 OID 18965)
-- Name: ilce_ilceID_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public."ilce_ilceID_seq"
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public."ilce_ilceID_seq" OWNER TO postgres;

--
-- TOC entry 3113 (class 0 OID 0)
-- Dependencies: 206
-- Name: ilce_ilceID_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public."ilce_ilceID_seq" OWNED BY public.ilce.ilceid;


--
-- TOC entry 207 (class 1259 OID 18967)
-- Name: ilce_sehirID_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public."ilce_sehirID_seq"
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public."ilce_sehirID_seq" OWNER TO postgres;

--
-- TOC entry 3114 (class 0 OID 0)
-- Dependencies: 207
-- Name: ilce_sehirID_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public."ilce_sehirID_seq" OWNED BY public.ilce.sehirid;


--
-- TOC entry 238 (class 1259 OID 19241)
-- Name: kitap; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.kitap (
    kitapid integer NOT NULL,
    kitapisim text,
    fiyat integer,
    stokmiktari integer,
    dersid integer NOT NULL
);


ALTER TABLE public.kitap OWNER TO postgres;

--
-- TOC entry 237 (class 1259 OID 19239)
-- Name: kitap_dersID_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public."kitap_dersID_seq"
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public."kitap_dersID_seq" OWNER TO postgres;

--
-- TOC entry 3115 (class 0 OID 0)
-- Dependencies: 237
-- Name: kitap_dersID_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public."kitap_dersID_seq" OWNED BY public.kitap.dersid;


--
-- TOC entry 236 (class 1259 OID 19237)
-- Name: kitap_kitapID_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public."kitap_kitapID_seq"
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public."kitap_kitapID_seq" OWNER TO postgres;

--
-- TOC entry 3116 (class 0 OID 0)
-- Dependencies: 236
-- Name: kitap_kitapID_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public."kitap_kitapID_seq" OWNED BY public.kitap.kitapid;


--
-- TOC entry 216 (class 1259 OID 19027)
-- Name: kullanici; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.kullanici (
    kullaniciid integer NOT NULL,
    ad text,
    soyad text,
    kullaniciadi text,
    sifre bigint,
    yas integer,
    cinsiyet text,
    kullanicituru text
);


ALTER TABLE public.kullanici OWNER TO postgres;

--
-- TOC entry 215 (class 1259 OID 19025)
-- Name: kullanici_kullaniciID_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public."kullanici_kullaniciID_seq"
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public."kullanici_kullaniciID_seq" OWNER TO postgres;

--
-- TOC entry 3117 (class 0 OID 0)
-- Dependencies: 215
-- Name: kullanici_kullaniciID_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public."kullanici_kullaniciID_seq" OWNED BY public.kullanici.kullaniciid;


--
-- TOC entry 221 (class 1259 OID 19051)
-- Name: ogrenci; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.ogrenci (
    ogrenciid integer NOT NULL,
    adresid integer NOT NULL,
    adsoyad text
);


ALTER TABLE public.ogrenci OWNER TO postgres;

--
-- TOC entry 220 (class 1259 OID 19049)
-- Name: ogrenci_adresID_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public."ogrenci_adresID_seq"
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public."ogrenci_adresID_seq" OWNER TO postgres;

--
-- TOC entry 3118 (class 0 OID 0)
-- Dependencies: 220
-- Name: ogrenci_adresID_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public."ogrenci_adresID_seq" OWNED BY public.ogrenci.adresid;


--
-- TOC entry 219 (class 1259 OID 19047)
-- Name: ogrenci_ogrenciID_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public."ogrenci_ogrenciID_seq"
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public."ogrenci_ogrenciID_seq" OWNER TO postgres;

--
-- TOC entry 3119 (class 0 OID 0)
-- Dependencies: 219
-- Name: ogrenci_ogrenciID_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public."ogrenci_ogrenciID_seq" OWNED BY public.ogrenci.ogrenciid;


--
-- TOC entry 218 (class 1259 OID 19038)
-- Name: ogrenciadres; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.ogrenciadres (
    adresid integer NOT NULL,
    sehir text,
    ilce text,
    detay text
);


ALTER TABLE public.ogrenciadres OWNER TO postgres;

--
-- TOC entry 217 (class 1259 OID 19036)
-- Name: ogrenciadres_adresID_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public."ogrenciadres_adresID_seq"
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public."ogrenciadres_adresID_seq" OWNER TO postgres;

--
-- TOC entry 3120 (class 0 OID 0)
-- Dependencies: 217
-- Name: ogrenciadres_adresID_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public."ogrenciadres_adresID_seq" OWNED BY public.ogrenciadres.adresid;


--
-- TOC entry 224 (class 1259 OID 19075)
-- Name: ogretmen; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.ogretmen (
    ogretmenid integer NOT NULL,
    bolumid integer NOT NULL,
    adsoyad text
);


ALTER TABLE public.ogretmen OWNER TO postgres;

--
-- TOC entry 223 (class 1259 OID 19073)
-- Name: ogretmen_bolumID_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public."ogretmen_bolumID_seq"
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public."ogretmen_bolumID_seq" OWNER TO postgres;

--
-- TOC entry 3121 (class 0 OID 0)
-- Dependencies: 223
-- Name: ogretmen_bolumID_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public."ogretmen_bolumID_seq" OWNED BY public.ogretmen.bolumid;


--
-- TOC entry 232 (class 1259 OID 19199)
-- Name: ogretmen_dershane; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.ogretmen_dershane (
    ogretmenid integer NOT NULL,
    dershaneid integer NOT NULL
);


ALTER TABLE public.ogretmen_dershane OWNER TO postgres;

--
-- TOC entry 231 (class 1259 OID 19197)
-- Name: ogretmen_dershane_dershaneID_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public."ogretmen_dershane_dershaneID_seq"
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public."ogretmen_dershane_dershaneID_seq" OWNER TO postgres;

--
-- TOC entry 3122 (class 0 OID 0)
-- Dependencies: 231
-- Name: ogretmen_dershane_dershaneID_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public."ogretmen_dershane_dershaneID_seq" OWNED BY public.ogretmen_dershane.dershaneid;


--
-- TOC entry 230 (class 1259 OID 19195)
-- Name: ogretmen_dershane_ogretmenID_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public."ogretmen_dershane_ogretmenID_seq"
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public."ogretmen_dershane_ogretmenID_seq" OWNER TO postgres;

--
-- TOC entry 3123 (class 0 OID 0)
-- Dependencies: 230
-- Name: ogretmen_dershane_ogretmenID_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public."ogretmen_dershane_ogretmenID_seq" OWNED BY public.ogretmen_dershane.ogretmenid;


--
-- TOC entry 222 (class 1259 OID 19071)
-- Name: ogretmen_ogretmenID_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public."ogretmen_ogretmenID_seq"
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public."ogretmen_ogretmenID_seq" OWNER TO postgres;

--
-- TOC entry 3124 (class 0 OID 0)
-- Dependencies: 222
-- Name: ogretmen_ogretmenID_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public."ogretmen_ogretmenID_seq" OWNED BY public.ogretmen.ogretmenid;


--
-- TOC entry 226 (class 1259 OID 19114)
-- Name: ozelders; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.ozelders (
    ozeldersid integer NOT NULL,
    dershaneid integer NOT NULL,
    bolumid integer NOT NULL,
    dersid integer NOT NULL,
    ogretmenid integer NOT NULL,
    ogrenciid integer NOT NULL
);


ALTER TABLE public.ozelders OWNER TO postgres;

--
-- TOC entry 244 (class 1259 OID 19343)
-- Name: ozelders_bolumID_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public."ozelders_bolumID_seq"
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public."ozelders_bolumID_seq" OWNER TO postgres;

--
-- TOC entry 3125 (class 0 OID 0)
-- Dependencies: 244
-- Name: ozelders_bolumID_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public."ozelders_bolumID_seq" OWNED BY public.ozelders.bolumid;


--
-- TOC entry 245 (class 1259 OID 19350)
-- Name: ozelders_dersID_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public."ozelders_dersID_seq"
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public."ozelders_dersID_seq" OWNER TO postgres;

--
-- TOC entry 3126 (class 0 OID 0)
-- Dependencies: 245
-- Name: ozelders_dersID_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public."ozelders_dersID_seq" OWNED BY public.ozelders.dersid;


--
-- TOC entry 243 (class 1259 OID 19336)
-- Name: ozelders_dershaneID_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public."ozelders_dershaneID_seq"
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public."ozelders_dershaneID_seq" OWNER TO postgres;

--
-- TOC entry 3127 (class 0 OID 0)
-- Dependencies: 243
-- Name: ozelders_dershaneID_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public."ozelders_dershaneID_seq" OWNED BY public.ozelders.dershaneid;


--
-- TOC entry 247 (class 1259 OID 19384)
-- Name: ozelders_ogrenciID_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public."ozelders_ogrenciID_seq"
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public."ozelders_ogrenciID_seq" OWNER TO postgres;

--
-- TOC entry 3128 (class 0 OID 0)
-- Dependencies: 247
-- Name: ozelders_ogrenciID_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public."ozelders_ogrenciID_seq" OWNED BY public.ozelders.ogrenciid;


--
-- TOC entry 246 (class 1259 OID 19377)
-- Name: ozelders_ogretmenID_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public."ozelders_ogretmenID_seq"
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public."ozelders_ogretmenID_seq" OWNER TO postgres;

--
-- TOC entry 3129 (class 0 OID 0)
-- Dependencies: 246
-- Name: ozelders_ogretmenID_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public."ozelders_ogretmenID_seq" OWNED BY public.ozelders.ogretmenid;


--
-- TOC entry 225 (class 1259 OID 19112)
-- Name: ozelders_ozelDersID_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public."ozelders_ozelDersID_seq"
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public."ozelders_ozelDersID_seq" OWNER TO postgres;

--
-- TOC entry 3130 (class 0 OID 0)
-- Dependencies: 225
-- Name: ozelders_ozelDersID_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public."ozelders_ozelDersID_seq" OWNED BY public.ozelders.ozeldersid;


--
-- TOC entry 205 (class 1259 OID 18956)
-- Name: sehir; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.sehir (
    sehirid integer NOT NULL,
    sehiradi text
);


ALTER TABLE public.sehir OWNER TO postgres;

--
-- TOC entry 204 (class 1259 OID 18954)
-- Name: sehir_sehirID_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public."sehir_sehirID_seq"
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public."sehir_sehirID_seq" OWNER TO postgres;

--
-- TOC entry 3131 (class 0 OID 0)
-- Dependencies: 204
-- Name: sehir_sehirID_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public."sehir_sehirID_seq" OWNED BY public.sehir.sehirid;


--
-- TOC entry 242 (class 1259 OID 19263)
-- Name: siparis; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.siparis (
    siparisid integer NOT NULL,
    kitapid integer NOT NULL,
    ogrenciid integer NOT NULL
);


ALTER TABLE public.siparis OWNER TO postgres;

--
-- TOC entry 240 (class 1259 OID 19259)
-- Name: siparis_kitapID_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public."siparis_kitapID_seq"
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public."siparis_kitapID_seq" OWNER TO postgres;

--
-- TOC entry 3132 (class 0 OID 0)
-- Dependencies: 240
-- Name: siparis_kitapID_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public."siparis_kitapID_seq" OWNED BY public.siparis.kitapid;


--
-- TOC entry 241 (class 1259 OID 19261)
-- Name: siparis_ogrenciID_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public."siparis_ogrenciID_seq"
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public."siparis_ogrenciID_seq" OWNER TO postgres;

--
-- TOC entry 3133 (class 0 OID 0)
-- Dependencies: 241
-- Name: siparis_ogrenciID_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public."siparis_ogrenciID_seq" OWNED BY public.siparis.ogrenciid;


--
-- TOC entry 239 (class 1259 OID 19257)
-- Name: siparis_siparisID_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public."siparis_siparisID_seq"
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public."siparis_siparisID_seq" OWNER TO postgres;

--
-- TOC entry 3134 (class 0 OID 0)
-- Dependencies: 239
-- Name: siparis_siparisID_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public."siparis_siparisID_seq" OWNED BY public.siparis.siparisid;


--
-- TOC entry 248 (class 1259 OID 19425)
-- Name: toplam_kullanici; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.toplam_kullanici (
    toplam integer
);


ALTER TABLE public.toplam_kullanici OWNER TO postgres;

--
-- TOC entry 2829 (class 2604 OID 18948)
-- Name: bolum bolumid; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.bolum ALTER COLUMN bolumid SET DEFAULT nextval('public."bolum_bolumID_seq"'::regclass);


--
-- TOC entry 2849 (class 2604 OID 19180)
-- Name: bolum_dershane bolumid; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.bolum_dershane ALTER COLUMN bolumid SET DEFAULT nextval('public."bolum_dershane_bolumID_seq"'::regclass);


--
-- TOC entry 2850 (class 2604 OID 19181)
-- Name: bolum_dershane dershaneid; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.bolum_dershane ALTER COLUMN dershaneid SET DEFAULT nextval('public."bolum_dershane_dershaneID_seq"'::regclass);


--
-- TOC entry 2853 (class 2604 OID 19225)
-- Name: ders dersid; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.ders ALTER COLUMN dersid SET DEFAULT nextval('public."ders_dersID_seq"'::regclass);


--
-- TOC entry 2854 (class 2604 OID 19226)
-- Name: ders bolumid; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.ders ALTER COLUMN bolumid SET DEFAULT nextval('public."ders_bolumID_seq"'::regclass);


--
-- TOC entry 2835 (class 2604 OID 19012)
-- Name: dershane dershaneid; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.dershane ALTER COLUMN dershaneid SET DEFAULT nextval('public."dershane_dershaneID_seq"'::regclass);


--
-- TOC entry 2836 (class 2604 OID 19013)
-- Name: dershane dershaneadresid; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.dershane ALTER COLUMN dershaneadresid SET DEFAULT nextval('public."dershane_dershaneAdresID_seq"'::regclass);


--
-- TOC entry 2833 (class 2604 OID 18992)
-- Name: dershaneadres adresid; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.dershaneadres ALTER COLUMN adresid SET DEFAULT nextval('public."dershaneadres_adresID_seq"'::regclass);


--
-- TOC entry 2834 (class 2604 OID 18993)
-- Name: dershaneadres ilceid; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.dershaneadres ALTER COLUMN ilceid SET DEFAULT nextval('public."dershaneadres_ilceID_seq"'::regclass);


--
-- TOC entry 2831 (class 2604 OID 18972)
-- Name: ilce ilceid; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.ilce ALTER COLUMN ilceid SET DEFAULT nextval('public."ilce_ilceID_seq"'::regclass);


--
-- TOC entry 2832 (class 2604 OID 18973)
-- Name: ilce sehirid; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.ilce ALTER COLUMN sehirid SET DEFAULT nextval('public."ilce_sehirID_seq"'::regclass);


--
-- TOC entry 2855 (class 2604 OID 19244)
-- Name: kitap kitapid; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.kitap ALTER COLUMN kitapid SET DEFAULT nextval('public."kitap_kitapID_seq"'::regclass);


--
-- TOC entry 2856 (class 2604 OID 19245)
-- Name: kitap dersid; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.kitap ALTER COLUMN dersid SET DEFAULT nextval('public."kitap_dersID_seq"'::regclass);


--
-- TOC entry 2837 (class 2604 OID 19030)
-- Name: kullanici kullaniciid; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.kullanici ALTER COLUMN kullaniciid SET DEFAULT nextval('public."kullanici_kullaniciID_seq"'::regclass);


--
-- TOC entry 2839 (class 2604 OID 19054)
-- Name: ogrenci ogrenciid; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.ogrenci ALTER COLUMN ogrenciid SET DEFAULT nextval('public."ogrenci_ogrenciID_seq"'::regclass);


--
-- TOC entry 2840 (class 2604 OID 19055)
-- Name: ogrenci adresid; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.ogrenci ALTER COLUMN adresid SET DEFAULT nextval('public."ogrenci_adresID_seq"'::regclass);


--
-- TOC entry 2838 (class 2604 OID 19041)
-- Name: ogrenciadres adresid; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.ogrenciadres ALTER COLUMN adresid SET DEFAULT nextval('public."ogrenciadres_adresID_seq"'::regclass);


--
-- TOC entry 2841 (class 2604 OID 19078)
-- Name: ogretmen ogretmenid; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.ogretmen ALTER COLUMN ogretmenid SET DEFAULT nextval('public."ogretmen_ogretmenID_seq"'::regclass);


--
-- TOC entry 2842 (class 2604 OID 19079)
-- Name: ogretmen bolumid; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.ogretmen ALTER COLUMN bolumid SET DEFAULT nextval('public."ogretmen_bolumID_seq"'::regclass);


--
-- TOC entry 2851 (class 2604 OID 19202)
-- Name: ogretmen_dershane ogretmenid; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.ogretmen_dershane ALTER COLUMN ogretmenid SET DEFAULT nextval('public."ogretmen_dershane_ogretmenID_seq"'::regclass);


--
-- TOC entry 2852 (class 2604 OID 19203)
-- Name: ogretmen_dershane dershaneid; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.ogretmen_dershane ALTER COLUMN dershaneid SET DEFAULT nextval('public."ogretmen_dershane_dershaneID_seq"'::regclass);


--
-- TOC entry 2843 (class 2604 OID 19117)
-- Name: ozelders ozeldersid; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.ozelders ALTER COLUMN ozeldersid SET DEFAULT nextval('public."ozelders_ozelDersID_seq"'::regclass);


--
-- TOC entry 2844 (class 2604 OID 19338)
-- Name: ozelders dershaneid; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.ozelders ALTER COLUMN dershaneid SET DEFAULT nextval('public."ozelders_dershaneID_seq"'::regclass);


--
-- TOC entry 2845 (class 2604 OID 19345)
-- Name: ozelders bolumid; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.ozelders ALTER COLUMN bolumid SET DEFAULT nextval('public."ozelders_bolumID_seq"'::regclass);


--
-- TOC entry 2846 (class 2604 OID 19352)
-- Name: ozelders dersid; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.ozelders ALTER COLUMN dersid SET DEFAULT nextval('public."ozelders_dersID_seq"'::regclass);


--
-- TOC entry 2847 (class 2604 OID 19379)
-- Name: ozelders ogretmenid; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.ozelders ALTER COLUMN ogretmenid SET DEFAULT nextval('public."ozelders_ogretmenID_seq"'::regclass);


--
-- TOC entry 2848 (class 2604 OID 19386)
-- Name: ozelders ogrenciid; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.ozelders ALTER COLUMN ogrenciid SET DEFAULT nextval('public."ozelders_ogrenciID_seq"'::regclass);


--
-- TOC entry 2830 (class 2604 OID 18959)
-- Name: sehir sehirid; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.sehir ALTER COLUMN sehirid SET DEFAULT nextval('public."sehir_sehirID_seq"'::regclass);


--
-- TOC entry 2857 (class 2604 OID 19266)
-- Name: siparis siparisid; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.siparis ALTER COLUMN siparisid SET DEFAULT nextval('public."siparis_siparisID_seq"'::regclass);


--
-- TOC entry 2858 (class 2604 OID 19267)
-- Name: siparis kitapid; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.siparis ALTER COLUMN kitapid SET DEFAULT nextval('public."siparis_kitapID_seq"'::regclass);


--
-- TOC entry 2859 (class 2604 OID 19268)
-- Name: siparis ogrenciid; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.siparis ALTER COLUMN ogrenciid SET DEFAULT nextval('public."siparis_ogrenciID_seq"'::regclass);


--
-- TOC entry 3053 (class 0 OID 18945)
-- Dependencies: 203
-- Data for Name: bolum; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.bolum (bolumid, bolumadi) FROM stdin;
1	bilgisayar muhendisligi
2	makine muhendisligi
3	elektrik muhendisligi
4	endustri muhendisligi
5	matematik muhendisligi
6	fizik muhendisligi
7	malzeme muhendisligi
8	biyoloji muhendisligi
9	kimya muhendisligi
10	gemi muhendisligi
\.


--
-- TOC entry 3079 (class 0 OID 19177)
-- Dependencies: 229
-- Data for Name: bolum_dershane; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.bolum_dershane (bolumid, dershaneid) FROM stdin;
1	1
2	1
3	1
4	1
5	1
6	1
7	1
8	1
9	1
10	1
1	2
2	2
3	2
4	2
5	2
6	2
7	2
8	2
9	2
10	2
1	3
2	3
3	3
4	3
5	3
6	3
7	3
8	3
9	3
10	3
1	4
2	4
3	4
4	4
5	4
6	4
7	4
8	4
9	4
10	4
1	5
2	5
3	5
4	5
5	5
6	5
7	5
8	5
9	5
10	5
1	6
2	6
3	6
4	6
5	6
6	6
7	6
8	6
9	6
10	6
\.


--
-- TOC entry 3085 (class 0 OID 19222)
-- Dependencies: 235
-- Data for Name: ders; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.ders (dersid, dersadi, bolumid) FROM stdin;
2	c++	1
3	c#	1
4	sql	1
5	java	1
6	python	1
7	veri yapilari	1
8	yapay zeka	1
9	html	1
10	css	1
11	web	1
12	makine giris	2
13	carklar	2
14	makine cizim	2
15	cizim	3
16	devreler	3
17	elektronik	3
18	c++	3
19	python	4
20	emg	4
21	analiz	4
22	mat1	5
23	mat2	5
24	lineer	5
25	olasilik	5
26	fizik1	6
27	fizik2	6
28	elektrik	6
29	mmg	7
30	kimya	7
31	malzemeler	7
32	biyoloji1	8
33	biyoloji2	8
34	canlilar	8
35	sistemler	8
36	dolasim	8
37	kemik	8
38	kas sistemi	8
39	ic hastaliklar	8
40	kimya1	9
41	kimya2	9
42	gemi teknigi	10
43	gemi makine	10
44	gemi yonetimi	10
1	c program	1
\.


--
-- TOC entry 3064 (class 0 OID 19009)
-- Dependencies: 214
-- Data for Name: dershane; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.dershane (dershaneid, dershaneadi, dershanetur, dershanesubesayisi, dershaneadresid) FROM stdin;
1	GaziosmanPasa Final	devlet	2	1
2	Arnavutköy Final	devlet	2	2
3	Besiktaş Boğaziçi	ozel	4	3
4	Bebek Boğaziçi	ozel	4	4
5	Eyüp Boğaziçi	ozel	4	5
6	Şişli Boğaziçi	ozel	4	6
\.


--
-- TOC entry 3061 (class 0 OID 18989)
-- Dependencies: 211
-- Data for Name: dershaneadres; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.dershaneadres (adresid, ilceid, detay) FROM stdin;
1	1	gaziosmanpasa x mahllesi
2	2	arnavutkoy q mahllesi
3	3	besiktas w mahllesi
4	4	bebek w mahllesi
5	5	eyup e mahllesi
6	6	sisli r mahllesi
\.


--
-- TOC entry 3058 (class 0 OID 18969)
-- Dependencies: 208
-- Data for Name: ilce; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.ilce (ilceid, sehirid, ilcead) FROM stdin;
1	1	gaziosmanpasa
2	1	arnavutkoy
3	1	besiktas
4	1	bebek
5	1	eyup
6	1	sisli
7	1	etiler
8	1	basaksehir
9	1	pendik
10	1	kadikoy
11	1	fatih
12	1	kaynarca
13	1	mecidyekoy
14	1	bakirkoy
15	1	atakoy
16	1	kucukcekmece
17	1	buyukcekmece
18	1	sultangazi
19	1	bayrampasa
20	1	umraniye
\.


--
-- TOC entry 3088 (class 0 OID 19241)
-- Dependencies: 238
-- Data for Name: kitap; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.kitap (kitapid, kitapisim, fiyat, stokmiktari, dersid) FROM stdin;
5	c# code	95	100	2
6	c# ogreniyorum	90	100	2
7	sql ogreniyorum	90	100	3
8	sql code	60	170	3
9	java code	40	170	4
10	python code	50	60	5
11	python 	60	60	5
12	c++ ile veri yapilari 	40	40	6
13	yapay zeka	70	40	7
14	html	80	50	8
15	css	80	50	9
16	web pro	80	60	10
17	machine	35	90	11
18	carklar	35	90	12
19	makine c	65	90	13
20	cizim dersi	65	90	13
21	cizim dersi	65	90	14
22	devreleri tani	50	90	15
23	elektronik mh	80	90	16
24	c++ learn	80	90	17
25	python learn	80	90	17
26	python learn	60	90	18
27	python	60	90	18
28	endustri giris	40	100	19
29	analizleme	40	100	20
30	cal mat1	40	100	21
31	cal mat2	40	100	22
32	cal lineer	60	100	23
33	olasilik ogren	60	100	24
34	fizik1	65	100	25
35	fizik2	65	100	26
36	electric	65	100	27
37	malzeme	35	100	28
38	kimya1	35	100	29
39	malzeme tanim	35	100	30
40	biyo	75	100	31
41	biyoloji	75	100	32
42	biyoloji2	75	100	32
43	canlilari tani	75	100	33
44	sistemler	55	100	34
45	dolasim1	50	100	35
46	kemikler	50	100	36
47	kemik	50	100	37
48	kas	50	100	38
49	dahiliye	50	100	38
50	kimya1	70	100	39
51	kimya2	70	100	40
52	gemi tec	70	100	41
53	gemi mac	70	100	42
54	gemi yonetimi	70	100	43
55	gemi	70	100	44
2	c++ ogreniyorum	100	100	1
4	c++ code	95	100	1
3	c++ dersi	100	100	1
1	c	90	90	1
\.


--
-- TOC entry 3066 (class 0 OID 19027)
-- Dependencies: 216
-- Data for Name: kullanici; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.kullanici (kullaniciid, ad, soyad, kullaniciadi, sifre, yas, cinsiyet, kullanicituru) FROM stdin;
1	omer	faruk	omerfaruk69	123456	34	erkek	ogretmen
2	taha	yasin	tahayasin69	123456	43	erkek	ogretmen
3	emre	akbaba	emreakbaba3	121212	20	erkek	ogrenci
5	cenk	tosun	cenktosun5	432454	20	erkek	ogrenci
6	cengiz	aslan	cengizaslan6	332211	21	erkek	ogrenci
7	gokhan	oklu	gokhanoklu123	98763	55	erkek	ogretmen
8	merih	demiral	merihdemirall34	123456	23	erkek	ogrenci
9	zeki	ak	zekiak98	237987	22	erkek	ogrenci
10	tufan	koyun	koyuntufann	853524	36	erkek	ogretmen
11	mehmet	emin	memoemin	958974	36	erkek	ogretmen
12	can	yavuz	bayburt69	342312	37	erkek	ogretmen
13	mehmet	akif	mehmetakif1212	654345	48	erkek	ogretmen
14	ayse	kardelen	ayselikar	876543	35	kadin	ogretmen
15	fatma	tok	fatmatok66	234554	32	kadin	ogretmen
16	kadir	ali	kadirali71	334442	32	erkek	ogretmen
17	selin	cebeci	selinnceb	934857	39	kadin	ogretmen
18	tayfun	sert	tayfunset	123456	31	erkek	ogretmen
19	emre	demir	emreedemr	123456	44	erkek	ogretmen
20	ahmet	aslan	23ahmet65	123456	48	erkek	ogretmen
21	ebru	terzi	1ebruterzi1	876543	35	kadin	ogretmen
22	yaren	ser	yarenser567	234554	35	kadin	ogretmen
23	sefa	kar	sefakar	334442	35	erkek	ogretmen
24	melih	cenk	melihcengo	934857	39	erkek	ogretmen
25	nazir	ay	nazirhann	123456	31	erkek	ogretmen
26	alim	demir	alimdemirr	123456	44	erkek	ogretmen
27	eren	yol	erenyoll	654345	48	erkek	ogretmen
28	dudu	berber	dudu122	876543	35	kadin	ogretmen
29	ezgi	benli	ezgii21	234554	35	kadin	ogretmen
30	umut	umut	umutumut	334442	32	erkek	ogretmen
31	serap	kahveci	serapkahve	934857	39	kadin	ogretmen
32	nihat	derman	nihatdrmn	123456	39	erkek	ogretmen
33	taha	er	tahaer	974634	24	erkek	ogrenci
34	furkan	zorlu	furkanzorlu	232154	22	erkek	ogrenci
35	taha	bal	tahabal	974634	22	erkek	ogrenci
36	samet	ilgin	samcoilgin	234543	22	erkek	ogrenci
37	okan	buruk	okanburukk	976544	31	erkek	ogretmen
38	okan	bay	okanbay	857463	31	erkek	ogretmen
4	arda	turan	ardaturan4	123456	20	erkek	ogrenci
\.


--
-- TOC entry 3071 (class 0 OID 19051)
-- Dependencies: 221
-- Data for Name: ogrenci; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.ogrenci (ogrenciid, adresid, adsoyad) FROM stdin;
3	1	Emre Akbaba
4	2	Arda Turan
5	3	Cenk Tosun
6	4	Cengiz Aslan
8	5	Merih Demiral
9	6	Zeki Ak
33	7	Taha Er
34	8	Furkan Zorlu
35	9	Taha Bal
36	10	Samet İlgin
\.


--
-- TOC entry 3068 (class 0 OID 19038)
-- Dependencies: 218
-- Data for Name: ogrenciadres; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.ogrenciadres (adresid, sehir, ilce, detay) FROM stdin;
1	istanbul	gaziosmanpasa	gaziosmanpasa yeni mahalle
2	istanbul	etiler	etiler eski mahalle
3	istanbul	besiktas	besiktas mahallesi No 3 daire 1
4	istanbul	arnavutkoy	arka mahalle No 34 daire 2
5	istanbul	kadikoy	kavşak mahallesi No 14 daire 6
6	istanbul	mecidyekoy	sari mahallesi No 34 daire 8
7	istanbul	eyup	mevlana mahallesi No 123 daire 12
8	istanbul	besiktas	sur mahallesi No 13 daire 2
9	istanbul	kucukcekmece	alt mahallesi No 123 daire 4
10	istanbul	buyukcekmece	ust mahallesi No 12 daire 4
\.


--
-- TOC entry 3074 (class 0 OID 19075)
-- Dependencies: 224
-- Data for Name: ogretmen; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.ogretmen (ogretmenid, bolumid, adsoyad) FROM stdin;
1	1	Ömer Faruk
2	1	Taha Yasin
7	1	Gökhan Oklu
10	1	Tufan Koyun
11	1	Mehmet Emin
12	1	Can Yavuz
13	1	Mehmet Akif
14	1	Ayşe Kardelen
15	1	Fatma Tok
16	2	Kadir Ali
17	2	Selin Cebeci
18	2	Tayfun Sert
19	2	Emre Demir
20	3	Ahmet Aslan
21	3	Ebru Terzi
22	3	Yaren Ser
23	3	Sefa Kar
24	4	Melih Cenk
25	4	Nazir Ay
26	5	Alim Demir
27	6	Eren Yol
28	6	Dudu Berber
29	7	Ezgi Benli
30	8	Umut Umut
31	9	Serap Kahveci
32	9	Nihat Derman
37	10	Okan Buruk
\.


--
-- TOC entry 3082 (class 0 OID 19199)
-- Dependencies: 232
-- Data for Name: ogretmen_dershane; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.ogretmen_dershane (ogretmenid, dershaneid) FROM stdin;
1	1
31	1
30	1
29	1
16	1
17	1
2	2
7	2
10	2
20	2
21	2
37	3
32	3
28	3
11	3
13	3
18	3
12	4
14	4
19	4
20	4
22	5
24	5
26	5
15	6
23	6
25	6
27	6
\.


--
-- TOC entry 3076 (class 0 OID 19114)
-- Dependencies: 226
-- Data for Name: ozelders; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.ozelders (ozeldersid, dershaneid, bolumid, dersid, ogretmenid, ogrenciid) FROM stdin;
3	2	1	1	2	5
1	1	1	1	1	3
2	1	1	1	1	4
4	2	1	1	2	3
\.


--
-- TOC entry 3055 (class 0 OID 18956)
-- Dependencies: 205
-- Data for Name: sehir; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.sehir (sehirid, sehiradi) FROM stdin;
1	istanbul
\.


--
-- TOC entry 3092 (class 0 OID 19263)
-- Dependencies: 242
-- Data for Name: siparis; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.siparis (siparisid, kitapid, ogrenciid) FROM stdin;
\.


--
-- TOC entry 3098 (class 0 OID 19425)
-- Dependencies: 248
-- Data for Name: toplam_kullanici; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.toplam_kullanici (toplam) FROM stdin;
38
\.


--
-- TOC entry 3135 (class 0 OID 0)
-- Dependencies: 202
-- Name: bolum_bolumID_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public."bolum_bolumID_seq"', 10, true);


--
-- TOC entry 3136 (class 0 OID 0)
-- Dependencies: 227
-- Name: bolum_dershane_bolumID_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public."bolum_dershane_bolumID_seq"', 1, false);


--
-- TOC entry 3137 (class 0 OID 0)
-- Dependencies: 228
-- Name: bolum_dershane_dershaneID_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public."bolum_dershane_dershaneID_seq"', 1, false);


--
-- TOC entry 3138 (class 0 OID 0)
-- Dependencies: 234
-- Name: ders_bolumID_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public."ders_bolumID_seq"', 1, false);


--
-- TOC entry 3139 (class 0 OID 0)
-- Dependencies: 233
-- Name: ders_dersID_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public."ders_dersID_seq"', 44, true);


--
-- TOC entry 3140 (class 0 OID 0)
-- Dependencies: 213
-- Name: dershane_dershaneAdresID_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public."dershane_dershaneAdresID_seq"', 1, false);


--
-- TOC entry 3141 (class 0 OID 0)
-- Dependencies: 212
-- Name: dershane_dershaneID_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public."dershane_dershaneID_seq"', 6, true);


--
-- TOC entry 3142 (class 0 OID 0)
-- Dependencies: 209
-- Name: dershaneadres_adresID_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public."dershaneadres_adresID_seq"', 6, true);


--
-- TOC entry 3143 (class 0 OID 0)
-- Dependencies: 210
-- Name: dershaneadres_ilceID_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public."dershaneadres_ilceID_seq"', 1, false);


--
-- TOC entry 3144 (class 0 OID 0)
-- Dependencies: 206
-- Name: ilce_ilceID_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public."ilce_ilceID_seq"', 20, true);


--
-- TOC entry 3145 (class 0 OID 0)
-- Dependencies: 207
-- Name: ilce_sehirID_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public."ilce_sehirID_seq"', 1, false);


--
-- TOC entry 3146 (class 0 OID 0)
-- Dependencies: 237
-- Name: kitap_dersID_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public."kitap_dersID_seq"', 1, false);


--
-- TOC entry 3147 (class 0 OID 0)
-- Dependencies: 236
-- Name: kitap_kitapID_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public."kitap_kitapID_seq"', 56, true);


--
-- TOC entry 3148 (class 0 OID 0)
-- Dependencies: 215
-- Name: kullanici_kullaniciID_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public."kullanici_kullaniciID_seq"', 40, true);


--
-- TOC entry 3149 (class 0 OID 0)
-- Dependencies: 220
-- Name: ogrenci_adresID_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public."ogrenci_adresID_seq"', 1, false);


--
-- TOC entry 3150 (class 0 OID 0)
-- Dependencies: 219
-- Name: ogrenci_ogrenciID_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public."ogrenci_ogrenciID_seq"', 1, false);


--
-- TOC entry 3151 (class 0 OID 0)
-- Dependencies: 217
-- Name: ogrenciadres_adresID_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public."ogrenciadres_adresID_seq"', 12, true);


--
-- TOC entry 3152 (class 0 OID 0)
-- Dependencies: 223
-- Name: ogretmen_bolumID_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public."ogretmen_bolumID_seq"', 1, false);


--
-- TOC entry 3153 (class 0 OID 0)
-- Dependencies: 231
-- Name: ogretmen_dershane_dershaneID_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public."ogretmen_dershane_dershaneID_seq"', 1, false);


--
-- TOC entry 3154 (class 0 OID 0)
-- Dependencies: 230
-- Name: ogretmen_dershane_ogretmenID_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public."ogretmen_dershane_ogretmenID_seq"', 1, false);


--
-- TOC entry 3155 (class 0 OID 0)
-- Dependencies: 222
-- Name: ogretmen_ogretmenID_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public."ogretmen_ogretmenID_seq"', 1, false);


--
-- TOC entry 3156 (class 0 OID 0)
-- Dependencies: 244
-- Name: ozelders_bolumID_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public."ozelders_bolumID_seq"', 1, false);


--
-- TOC entry 3157 (class 0 OID 0)
-- Dependencies: 245
-- Name: ozelders_dersID_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public."ozelders_dersID_seq"', 1, false);


--
-- TOC entry 3158 (class 0 OID 0)
-- Dependencies: 243
-- Name: ozelders_dershaneID_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public."ozelders_dershaneID_seq"', 1, false);


--
-- TOC entry 3159 (class 0 OID 0)
-- Dependencies: 247
-- Name: ozelders_ogrenciID_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public."ozelders_ogrenciID_seq"', 33, true);


--
-- TOC entry 3160 (class 0 OID 0)
-- Dependencies: 246
-- Name: ozelders_ogretmenID_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public."ozelders_ogretmenID_seq"', 1, false);


--
-- TOC entry 3161 (class 0 OID 0)
-- Dependencies: 225
-- Name: ozelders_ozelDersID_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public."ozelders_ozelDersID_seq"', 5, true);


--
-- TOC entry 3162 (class 0 OID 0)
-- Dependencies: 204
-- Name: sehir_sehirID_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public."sehir_sehirID_seq"', 1, true);


--
-- TOC entry 3163 (class 0 OID 0)
-- Dependencies: 240
-- Name: siparis_kitapID_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public."siparis_kitapID_seq"', 1, false);


--
-- TOC entry 3164 (class 0 OID 0)
-- Dependencies: 241
-- Name: siparis_ogrenciID_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public."siparis_ogrenciID_seq"', 1, false);


--
-- TOC entry 3165 (class 0 OID 0)
-- Dependencies: 239
-- Name: siparis_siparisID_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public."siparis_siparisID_seq"', 20, true);


--
-- TOC entry 2888 (class 2606 OID 19183)
-- Name: bolum_dershane bolum_dershane_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.bolum_dershane
    ADD CONSTRAINT bolum_dershane_pkey PRIMARY KEY (bolumid, dershaneid);


--
-- TOC entry 2861 (class 2606 OID 18953)
-- Name: bolum bolum_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.bolum
    ADD CONSTRAINT bolum_pkey PRIMARY KEY (bolumid);


--
-- TOC entry 2895 (class 2606 OID 19231)
-- Name: ders ders_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.ders
    ADD CONSTRAINT ders_pkey PRIMARY KEY (dersid);


--
-- TOC entry 2871 (class 2606 OID 19018)
-- Name: dershane dershane_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.dershane
    ADD CONSTRAINT dershane_pkey PRIMARY KEY (dershaneid);


--
-- TOC entry 2868 (class 2606 OID 18998)
-- Name: dershaneadres dershaneadres_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.dershaneadres
    ADD CONSTRAINT dershaneadres_pkey PRIMARY KEY (adresid);


--
-- TOC entry 2866 (class 2606 OID 18978)
-- Name: ilce ilce_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.ilce
    ADD CONSTRAINT ilce_pkey PRIMARY KEY (ilceid);


--
-- TOC entry 2898 (class 2606 OID 19250)
-- Name: kitap kitap_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.kitap
    ADD CONSTRAINT kitap_pkey PRIMARY KEY (kitapid);


--
-- TOC entry 2874 (class 2606 OID 19035)
-- Name: kullanici kullanici_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.kullanici
    ADD CONSTRAINT kullanici_pkey PRIMARY KEY (kullaniciid);


--
-- TOC entry 2879 (class 2606 OID 19057)
-- Name: ogrenci ogrenci_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.ogrenci
    ADD CONSTRAINT ogrenci_pkey PRIMARY KEY (ogrenciid);


--
-- TOC entry 2876 (class 2606 OID 19046)
-- Name: ogrenciadres ogrenciadres_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.ogrenciadres
    ADD CONSTRAINT ogrenciadres_pkey PRIMARY KEY (adresid);


--
-- TOC entry 2893 (class 2606 OID 19205)
-- Name: ogretmen_dershane ogretmen_dershane_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.ogretmen_dershane
    ADD CONSTRAINT ogretmen_dershane_pkey PRIMARY KEY (ogretmenid, dershaneid);


--
-- TOC entry 2882 (class 2606 OID 19081)
-- Name: ogretmen ogrtemen_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.ogretmen
    ADD CONSTRAINT ogrtemen_pkey PRIMARY KEY (ogretmenid);


--
-- TOC entry 2886 (class 2606 OID 19119)
-- Name: ozelders ozelders_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.ozelders
    ADD CONSTRAINT ozelders_pkey PRIMARY KEY (ozeldersid);


--
-- TOC entry 2863 (class 2606 OID 18964)
-- Name: sehir sehir_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.sehir
    ADD CONSTRAINT sehir_pkey PRIMARY KEY (sehirid);


--
-- TOC entry 2901 (class 2606 OID 19270)
-- Name: siparis siparis_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.siparis
    ADD CONSTRAINT siparis_pkey PRIMARY KEY (siparisid);


--
-- TOC entry 2877 (class 1259 OID 19068)
-- Name: fki_adresID_FK; Type: INDEX; Schema: public; Owner: postgres
--

CREATE INDEX "fki_adresID_FK" ON public.ogrenci USING btree (adresid);


--
-- TOC entry 2880 (class 1259 OID 19092)
-- Name: fki_bolumID_FK; Type: INDEX; Schema: public; Owner: postgres
--

CREATE INDEX "fki_bolumID_FK" ON public.ogretmen USING btree (bolumid);


--
-- TOC entry 2896 (class 1259 OID 19256)
-- Name: fki_dersID_FK; Type: INDEX; Schema: public; Owner: postgres
--

CREATE INDEX "fki_dersID_FK" ON public.kitap USING btree (dersid);


--
-- TOC entry 2872 (class 1259 OID 19024)
-- Name: fki_dershaneAdres_FK; Type: INDEX; Schema: public; Owner: postgres
--

CREATE INDEX "fki_dershaneAdres_FK" ON public.dershane USING btree (dershaneadresid);


--
-- TOC entry 2890 (class 1259 OID 19216)
-- Name: fki_dershaneID_FK; Type: INDEX; Schema: public; Owner: postgres
--

CREATE INDEX "fki_dershaneID_FK" ON public.ogretmen_dershane USING btree (dershaneid);


--
-- TOC entry 2889 (class 1259 OID 19194)
-- Name: fki_dershaneId_Fk; Type: INDEX; Schema: public; Owner: postgres
--

CREATE INDEX "fki_dershaneId_Fk" ON public.bolum_dershane USING btree (dershaneid);


--
-- TOC entry 2864 (class 1259 OID 18984)
-- Name: fki_ilID_FK; Type: INDEX; Schema: public; Owner: postgres
--

CREATE INDEX "fki_ilID_FK" ON public.ilce USING btree (sehirid);


--
-- TOC entry 2869 (class 1259 OID 19004)
-- Name: fki_ilceID_FK; Type: INDEX; Schema: public; Owner: postgres
--

CREATE INDEX "fki_ilceID_FK" ON public.dershaneadres USING btree (ilceid);


--
-- TOC entry 2899 (class 1259 OID 19281)
-- Name: fki_kitapID_FK; Type: INDEX; Schema: public; Owner: postgres
--

CREATE INDEX "fki_kitapID_FK" ON public.siparis USING btree (kitapid);


--
-- TOC entry 2883 (class 1259 OID 19402)
-- Name: fki_ogrenciID_FK; Type: INDEX; Schema: public; Owner: postgres
--

CREATE INDEX "fki_ogrenciID_FK" ON public.ozelders USING btree (ogrenciid);


--
-- TOC entry 2884 (class 1259 OID 19396)
-- Name: fki_ogretmenID_FK; Type: INDEX; Schema: public; Owner: postgres
--

CREATE INDEX "fki_ogretmenID_FK" ON public.ozelders USING btree (ogretmenid);


--
-- TOC entry 2891 (class 1259 OID 19217)
-- Name: fki_ogretmenID_ıd; Type: INDEX; Schema: public; Owner: postgres
--

CREATE INDEX "fki_ogretmenID_ıd" ON public.ogretmen_dershane USING btree (ogretmenid);


--
-- TOC entry 2924 (class 2620 OID 19436)
-- Name: siparis stokbul; Type: TRIGGER; Schema: public; Owner: postgres
--

CREATE TRIGGER stokbul AFTER INSERT ON public.siparis FOR EACH ROW EXECUTE FUNCTION public.stok();


--
-- TOC entry 2925 (class 2620 OID 19439)
-- Name: siparis stokbul2; Type: TRIGGER; Schema: public; Owner: postgres
--

CREATE TRIGGER stokbul2 AFTER DELETE ON public.siparis FOR EACH ROW EXECUTE FUNCTION public.stok2();


--
-- TOC entry 2922 (class 2620 OID 19429)
-- Name: kullanici toplambul; Type: TRIGGER; Schema: public; Owner: postgres
--

CREATE TRIGGER toplambul AFTER INSERT ON public.kullanici FOR EACH ROW EXECUTE FUNCTION public.toplam();


--
-- TOC entry 2923 (class 2620 OID 19432)
-- Name: kullanici toplambul2; Type: TRIGGER; Schema: public; Owner: postgres
--

CREATE TRIGGER toplambul2 AFTER DELETE ON public.kullanici FOR EACH ROW EXECUTE FUNCTION public.toplam2();


--
-- TOC entry 2905 (class 2606 OID 19058)
-- Name: ogrenci adresID_FK; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.ogrenci
    ADD CONSTRAINT "adresID_FK" FOREIGN KEY (adresid) REFERENCES public.ogrenciadres(adresid) ON UPDATE CASCADE ON DELETE CASCADE;


--
-- TOC entry 2907 (class 2606 OID 19082)
-- Name: ogretmen bolumID_FK; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.ogretmen
    ADD CONSTRAINT "bolumID_FK" FOREIGN KEY (bolumid) REFERENCES public.bolum(bolumid) ON UPDATE CASCADE ON DELETE CASCADE;


--
-- TOC entry 2914 (class 2606 OID 19184)
-- Name: bolum_dershane bolumID_FK; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.bolum_dershane
    ADD CONSTRAINT "bolumID_FK" FOREIGN KEY (bolumid) REFERENCES public.bolum(bolumid) ON UPDATE CASCADE ON DELETE CASCADE;


--
-- TOC entry 2918 (class 2606 OID 19232)
-- Name: ders bolumID_FK; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.ders
    ADD CONSTRAINT "bolumID_FK" FOREIGN KEY (bolumid) REFERENCES public.bolum(bolumid) ON UPDATE CASCADE ON DELETE CASCADE;


--
-- TOC entry 2909 (class 2606 OID 19357)
-- Name: ozelders bolumID_FK; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.ozelders
    ADD CONSTRAINT "bolumID_FK" FOREIGN KEY (bolumid) REFERENCES public.bolum(bolumid) ON UPDATE CASCADE ON DELETE CASCADE NOT VALID;


--
-- TOC entry 2919 (class 2606 OID 19251)
-- Name: kitap dersID_FK; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.kitap
    ADD CONSTRAINT "dersID_FK" FOREIGN KEY (dersid) REFERENCES public.ders(dersid) ON UPDATE CASCADE ON DELETE CASCADE;


--
-- TOC entry 2910 (class 2606 OID 19362)
-- Name: ozelders dersID_FK; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.ozelders
    ADD CONSTRAINT "dersID_FK" FOREIGN KEY (dersid) REFERENCES public.ders(dersid) ON UPDATE CASCADE ON DELETE CASCADE NOT VALID;


--
-- TOC entry 2904 (class 2606 OID 19019)
-- Name: dershane dershaneAdres_FK; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.dershane
    ADD CONSTRAINT "dershaneAdres_FK" FOREIGN KEY (dershaneadresid) REFERENCES public.dershaneadres(adresid) ON UPDATE CASCADE ON DELETE CASCADE;


--
-- TOC entry 2916 (class 2606 OID 19206)
-- Name: ogretmen_dershane dershaneID_FK; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.ogretmen_dershane
    ADD CONSTRAINT "dershaneID_FK" FOREIGN KEY (dershaneid) REFERENCES public.dershane(dershaneid) ON UPDATE CASCADE ON DELETE CASCADE;


--
-- TOC entry 2911 (class 2606 OID 19367)
-- Name: ozelders dershaneID_FK; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.ozelders
    ADD CONSTRAINT "dershaneID_FK" FOREIGN KEY (dershaneid) REFERENCES public.dershane(dershaneid) ON UPDATE CASCADE ON DELETE CASCADE NOT VALID;


--
-- TOC entry 2915 (class 2606 OID 19189)
-- Name: bolum_dershane dershaneId_Fk; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.bolum_dershane
    ADD CONSTRAINT "dershaneId_Fk" FOREIGN KEY (dershaneid) REFERENCES public.dershane(dershaneid) ON UPDATE CASCADE ON DELETE CASCADE;


--
-- TOC entry 2902 (class 2606 OID 18979)
-- Name: ilce ilID_FK; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.ilce
    ADD CONSTRAINT "ilID_FK" FOREIGN KEY (sehirid) REFERENCES public.sehir(sehirid) ON UPDATE CASCADE ON DELETE CASCADE;


--
-- TOC entry 2903 (class 2606 OID 18999)
-- Name: dershaneadres ilceID_FK; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.dershaneadres
    ADD CONSTRAINT "ilceID_FK" FOREIGN KEY (ilceid) REFERENCES public.ilce(ilceid) ON UPDATE CASCADE ON DELETE CASCADE;


--
-- TOC entry 2920 (class 2606 OID 19271)
-- Name: siparis kitapID_FK; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.siparis
    ADD CONSTRAINT "kitapID_FK" FOREIGN KEY (kitapid) REFERENCES public.kitap(kitapid) ON UPDATE CASCADE ON DELETE CASCADE;


--
-- TOC entry 2906 (class 2606 OID 19063)
-- Name: ogrenci ogrenciID_FK; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.ogrenci
    ADD CONSTRAINT "ogrenciID_FK" FOREIGN KEY (ogrenciid) REFERENCES public.kullanici(kullaniciid) ON UPDATE CASCADE ON DELETE CASCADE;


--
-- TOC entry 2921 (class 2606 OID 19276)
-- Name: siparis ogrenciID_FK; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.siparis
    ADD CONSTRAINT "ogrenciID_FK" FOREIGN KEY (ogrenciid) REFERENCES public.ogrenci(ogrenciid) ON UPDATE CASCADE ON DELETE CASCADE;


--
-- TOC entry 2913 (class 2606 OID 19397)
-- Name: ozelders ogrenciID_FK; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.ozelders
    ADD CONSTRAINT "ogrenciID_FK" FOREIGN KEY (ogrenciid) REFERENCES public.ogrenci(ogrenciid) ON UPDATE CASCADE ON DELETE CASCADE NOT VALID;


--
-- TOC entry 2908 (class 2606 OID 19087)
-- Name: ogretmen ogretmenID_FK; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.ogretmen
    ADD CONSTRAINT "ogretmenID_FK" FOREIGN KEY (ogretmenid) REFERENCES public.kullanici(kullaniciid) ON UPDATE CASCADE ON DELETE CASCADE;


--
-- TOC entry 2912 (class 2606 OID 19391)
-- Name: ozelders ogretmenID_FK; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.ozelders
    ADD CONSTRAINT "ogretmenID_FK" FOREIGN KEY (ogretmenid) REFERENCES public.ogretmen(ogretmenid) ON UPDATE CASCADE ON DELETE CASCADE NOT VALID;


--
-- TOC entry 2917 (class 2606 OID 19211)
-- Name: ogretmen_dershane ogretmenID_ıd; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.ogretmen_dershane
    ADD CONSTRAINT "ogretmenID_ıd" FOREIGN KEY (ogretmenid) REFERENCES public.ogretmen(ogretmenid) ON UPDATE CASCADE ON DELETE CASCADE;


-- Completed on 2020-12-30 12:12:37

--
-- PostgreSQL database dump complete
--

