import styles from './Home.module.css'

import Image1 from '../../assets/home-1.jpg'
import Image2 from '../../assets/home-2.jpg'
import Image3 from '../../assets/home-3.jpg'
import Logo from '../../assets/logo.png'

export default function Home() {
    return (
        <main>
            <section className={styles.containerHome}>
                <h1>Bem-vindo(a) ao <img className={styles.logo} src={Logo} alt="logo" /></h1>
                <div className={styles.div}>
                    <div>
                        <img src={Image1} alt="Desenho de Artista da Freepik" />
                    </div>
                    <div>
                        <h2>Site para divulgação de artes e fotografias</h2>
                        <p>Pinte, fotografe, publique, seja nosso artista, vão ser ações extremamente rápidas e praticas de fazer. Ou... O outro lado da moeda, procure, negocie, compre artes, podendo ser utilizadas em projetos de sua empresa com todos os direitos liberados.</p>
                    </div>
                </div>
            </section>
            <section className={styles.containerHome}>
                <div className={styles.div}>
                    <div>
                        <h2>Cresça sempre</h2>
                        <p>Seja reconhecido pela sua arte e/ou fotografias, se permita ser conhecido pelas grandes empresas. E você empresa, ache o artista pelo qual sempre sonhou para alavancar seus negócios.</p>
                    </div>
                    <div>
                        <img src={Image2} alt="Desenho de Artista da Freepik" />
                    </div>
                </div>
            </section>
            <section className={styles.containerHomeEnd}>
                <div className={styles.div}>
                    <div>
                        <img src={Image3} alt="Desenho de Artista da Freepik" />
                    </div>
                    <div>
                        <h2>Diversidade</h2>
                        <p>O artista livre de padrões pode publicar sua arte e/ou fotografia favorita ou mais chamativa, com isso, atingindo mais e mais interessados por seus projetos.</p>
                    </div>
                </div>
            </section>
        </main>
    );
}