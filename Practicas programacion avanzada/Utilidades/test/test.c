char eliminacionFisica()
{
    FILE *archivo;
    FILE *temporal;
    Producto producto;
    char elimina = 0;

    archivo = fopen("productos.dat", "rb");
    temporal = fopen("temporal.dat", "wb");

    if (archivo == NULL || temporal == NULL) {
        elimina = 0;
    } else {
        /* Se copia en el archivo temporal los registros válidos */
        fread(&producto, sizeof(producto), 1, archivo);
        while (!feof(archivo)) {
            if (producto.codigo != VALOR_CENTINELA) {
                fwrite(&producto, sizeof(producto), 1, temporal);
            }
            fread(&producto, sizeof(producto), 1, archivo);
        }
        /* Se cierran los archivos antes de borrar y renombrar */
        fclose(archivo);
        fclose(temporal);

        remove("productos.dat");
        rename("temporal.dat", "productos.dat");

        elimina = 1;
    }

    return elimina;
}
