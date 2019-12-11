//================================================================================================================================
//
//  Copyright (c) 2015-2019 VisionStar Information Technology (Shanghai) Co., Ltd. All Rights Reserved.
//  EasyAR is the registered trademark or trademark of VisionStar Information Technology (Shanghai) Co., Ltd in China
//  and other countries for the augmented reality technology developed by VisionStar Information Technology (Shanghai) Co., Ltd.
//
//================================================================================================================================
Shader "easyar/TextureSample" {
    Properties {
        _MainTex ("Base (RGB)", 2D) = "white" {}
        _Uvpoint1("point1", Vector) = (0 , 0 , 0 , 0)
        _Uvpoint2("point2", Vector) = (0 , 0 , 0 , 0)
        _Uvpoint3("point3", Vector) = (0 , 0 , 0 , 0)
        _Uvpoint4("point4", Vector) = (0 , 0 , 0 , 0)

    }
    SubShader {
        Tags { "Queue"="Transparent" "RenderType"="Transparent" }
        LOD 200

        Pass{
            Blend SrcAlpha OneMinusSrcAlpha

            CGPROGRAM
            #pragma vertex vert
            #pragma fragment frag
            #include "UnityCG.cginc"

            sampler2D _MainTex;
            float4 _MainTex_ST;
            float4 _Uvpoint1;
            float4 _Uvpoint2;
            float4 _Uvpoint3;
            float4 _Uvpoint4;

            struct v2f {
                float4  pos : SV_POSITION;
                float2  uv : TEXCOORD0;
                float4  fixedPos : TEXCOORD2;
            } ;

            v2f vert (appdata_base v)
            {
                v2f o;
                o.pos = UnityObjectToClipPos(v.vertex);
                o.uv = TRANSFORM_TEX(v.texcoord,_MainTex);
                float4 top = lerp(_Uvpoint1, _Uvpoint3, o.uv.x);
                float4 bottom = lerp(_Uvpoint2, _Uvpoint4, o.uv.x);
                float4 fixedPos = lerp(bottom, top, o.uv.y);
                o.fixedPos = ComputeGrabScreenPos(mul(UNITY_MATRIX_VP, fixedPos));
                return o;
            }

            float4 frag (v2f i) : COLOR
            {
                return tex2D(_MainTex, i.fixedPos.xy / i.fixedPos.w);
            }
            ENDCG
        }
    }
}
