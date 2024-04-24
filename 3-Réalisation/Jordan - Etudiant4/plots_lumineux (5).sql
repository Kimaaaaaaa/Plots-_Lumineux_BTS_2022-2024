-- phpMyAdmin SQL Dump
-- version 4.9.2
-- https://www.phpmyadmin.net/
--
-- Hôte : 127.0.0.1:3306
-- Généré le :  mar. 16 avr. 2024 à 15:29
-- Version du serveur :  10.4.10-MariaDB
-- Version de PHP :  7.3.12

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET AUTOCOMMIT = 0;
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Base de données :  `plots_lumineux`
--

-- --------------------------------------------------------

--
-- Structure de la table `configpartie`
--

DROP TABLE IF EXISTS `configpartie`;
CREATE TABLE IF NOT EXISTS `configpartie` (
  `idPartie` int(255) NOT NULL AUTO_INCREMENT,
  `couleurPlot` varchar(255) NOT NULL,
  `nbJoueur` int(255) NOT NULL,
  `nbPlots` int(255) NOT NULL,
  `tempsPourAppuyer` int(255) NOT NULL,
  `nbPlotsAppuyes` int(255) NOT NULL,
  PRIMARY KEY (`idPartie`)
) ENGINE=MyISAM AUTO_INCREMENT=28 DEFAULT CHARSET=latin1;

--
-- Déchargement des données de la table `configpartie`
--

INSERT INTO `configpartie` (`idPartie`, `couleurPlot`, `nbJoueur`, `nbPlots`, `tempsPourAppuyer`, `nbPlotsAppuyes`) VALUES
(1, 'rouge', 1, 4, 100, 5),
(2, 'SpinBox_QMLTYPE_20_QML_23(0x4ba0e6c0)', 0, 0, 0, 0),
(3, 'SpinBox_QMLTYPE_20_QML_23(0x4baff400)', 0, 0, 0, 0),
(4, 'SpinBox_QMLTYPE_20_QML_23(0x4c9a2980)', 0, 0, 0, 0),
(5, 'SpinBox_QMLTYPE_20_QML_23(0x4b9b2a40)', 0, 0, 0, 0),
(6, 'SpinBox_QMLTYPE_20_QML_23(0x4bb4d240)', 0, 0, 0, 0),
(7, 'SpinBox_QMLTYPE_20_QML_23(0x4bb37c40)', 0, 0, 0, 0),
(8, 'rouge', 1, 1, 5, 5),
(9, 'bleu', 2, 2, 5, 10),
(10, 'bleu', 2, 2, 30, 10),
(11, 'rouge', 1, 1, 5, 5),
(12, 'jaune', 1, 1, 5, 10),
(13, 'rouge', 1, 1, 5, 5),
(14, 'rouge', 1, 1, 5, 5),
(15, 'rouge', 1, 1, 5, 5),
(16, 'rouge', 1, 1, 5, 5),
(17, 'rouge', 1, 1, 5, 5),
(18, 'vert', 2, 3, 10, 15),
(19, 'rouge', 1, 1, 5, 5),
(20, 'rouge', 1, 1, 5, 5),
(21, 'rouge', 1, 1, 5, 5),
(22, 'rouge', 1, 1, 5, 5),
(23, 'rouge', 1, 1, 5, 5),
(24, 'rouge', 1, 1, 5, 5),
(25, 'rouge', 1, 1, 5, 5),
(26, 'rouge', 1, 1, 5, 5),
(27, 'rouge', 1, 1, 5, 5);

-- --------------------------------------------------------

--
-- Structure de la table `joueurs`
--

DROP TABLE IF EXISTS `joueurs`;
CREATE TABLE IF NOT EXISTS `joueurs` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `password` varchar(255) NOT NULL,
  `email` varchar(255) NOT NULL,
  `identifiant` varchar(255) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=MyISAM AUTO_INCREMENT=42 DEFAULT CHARSET=latin1;

--
-- Déchargement des données de la table `joueurs`
--

INSERT INTO `joueurs` (`id`, `password`, `email`, `identifiant`) VALUES
(7, '$2y$10$oY.3mLDTzMpIQRWpIL7nVOFYtu5K3mIwceUMPx1d3KbTsJiQgCWCi', 'test@test', 'test'),
(6, '$2y$10$66V7G2XIZ4Sv3tThEf6NJuCl3yyTVv395/sL4Tdw3Pm.1kxM6z20K', 'bobibo@gmail.com', 'bobibo11'),
(8, '$2y$10$lIJ0yZyyvSBtwrwdfBCYh.IJ2tY1UKEbdE3Grv4nocFMfJ5db3SKS', '2525@gmail.com', '2525'),
(9, 'j', 'j', 'j'),
(10, 'd', 'd', 'd'),
(11, 'd', 'd', 'd'),
(12, 'm', 'm', 'm'),
(13, 'm', 'm', 'm'),
(14, '1', '1', '1'),
(15, 'd', 'd', 'd'),
(16, 'd', 'd', 'd'),
(17, 's', 's', 's'),
(18, 's', 's', 's'),
(19, 'm', 'm', 'm'),
(20, 'm', 'm', 'm'),
(21, 'd', 'd', 'd'),
(22, '1', '1', '1'),
(23, 'i', 'i', 'i'),
(24, 'f', 'f', 'f'),
(25, 'a', 'a', 'a'),
(26, 'd', 'd', 'd'),
(27, 'f', 'f', 'f'),
(28, 't', 't', 't'),
(29, 'mot_de_passe', 'nouvel_utilisateur@example.com', 'nouvel_utilisateur'),
(30, 'mot_de_passe', 'nouvel_utilisateur@example.com', 'nouvel_utilisateur'),
(31, 'dd', 'qdsqdqdq@', 'dsqd'),
(32, 'aa', 'test@', 'test'),
(33, '14', 'zz@', 'aa'),
(34, '14', 'cerce@', 'adacxcxw'),
(35, '25', 'dada@', 'test2'),
(36, '14yyy', '25iop@', 'testui'),
(37, 'azerty+', 'test@com', 'test25'),
(38, 'AZERTY*', 'test088@', 'test088'),
(39, '12345.', 'poim@', 'poiu5'),
(40, '12345.', 'ertete@', 'dadada@'),
(41, '12345.', 'jep@', 'test0256');

-- --------------------------------------------------------

--
-- Structure de la table `partie`
--

DROP TABLE IF EXISTS `partie`;
CREATE TABLE IF NOT EXISTS `partie` (
  `idPartie` int(11) NOT NULL AUTO_INCREMENT,
  `date` date NOT NULL,
  `tempsReactionJ1` int(11) NOT NULL,
  `plotsAppuyes` int(255) NOT NULL,
  `identifiant` varchar(255) NOT NULL,
  PRIMARY KEY (`idPartie`)
) ENGINE=MyISAM AUTO_INCREMENT=15 DEFAULT CHARSET=latin1;

--
-- Déchargement des données de la table `partie`
--

INSERT INTO `partie` (`idPartie`, `date`, `tempsReactionJ1`, `plotsAppuyes`, `identifiant`) VALUES
(1, '2024-03-20', 160, 15, 'd'),
(2, '2024-03-21', 150, 33, 'aa'),
(3, '2024-03-25', 190, 8, 'test'),
(4, '2024-03-25', 130, 3, 'd'),
(5, '2024-03-25', 152, 18, 'test'),
(6, '2024-03-25', 121, 7, ''),
(7, '2024-03-25', 163, 5, ''),
(9, '2024-03-25', 220, 22, ''),
(11, '2024-03-25', 230, 22, ''),
(12, '2024-04-16', 175, 19, 'd');

-- --------------------------------------------------------

--
-- Structure de la table `tour`
--

DROP TABLE IF EXISTS `tour`;
CREATE TABLE IF NOT EXISTS `tour` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `tempsReactionJ1` int(11) NOT NULL,
  `validiteJ1` tinyint(1) NOT NULL,
  `partie_id` int(11) DEFAULT NULL,
  `tempsReactionJ2` int(11) NOT NULL,
  `date` date NOT NULL,
  `validiteJ2` int(11) NOT NULL,
  `joueur1_id` int(11) NOT NULL,
  `joueur2_id` int(11) NOT NULL,
  PRIMARY KEY (`id`),
  KEY `partie_id` (`partie_id`)
) ENGINE=MyISAM AUTO_INCREMENT=3 DEFAULT CHARSET=latin1;

--
-- Déchargement des données de la table `tour`
--

INSERT INTO `tour` (`id`, `tempsReactionJ1`, `validiteJ1`, `partie_id`, `tempsReactionJ2`, `date`, `validiteJ2`, `joueur1_id`, `joueur2_id`) VALUES
(1, 160, 45, 1, 150, '0000-00-00', 0, 0, 0),
(2, 160, 45, 2, 150, '2024-03-25', 40, 0, 0);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
