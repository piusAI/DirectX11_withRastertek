cbuffer MatrixBuffer
{
    matrix worldMatrix;
    matrix viewMatrix;
    matrix projectionMatrix;
};



struct VertexInputType
{
    float3 position : POSITION;
    float4 color : COLOR;
};

struct PixelInputType
{
    float4 position : SV_POSITION;
    float4 color : COLOR;
};


PixelInputType ColorVertexShader(VertexInputType input)
{
    PixelInputType output;
    
    //input.position.w = 1.0f;
    
    float4 pos = float4(input.position, 1.0f);
    

    
    output.position = mul(pos, worldMatrix);
    output.position = mul(output.position, viewMatrix);
    output.position = mul(output.position, projectionMatrix);

    output.color = input.color;

    
    return output;

}